#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>
#include <cassert>

using namespace std;

//
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
//
#define rep(i,b) for(int i=(0);i<(b);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(__typeof((b).begin()) a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}

int cond = (ll)1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

vector <string> db;
char buf[65536];
int dp[256][256];

const int alph = 'z' - 'a' + 1;

int bcost = (int)1e9;

int maxlen = 0;

struct node {
    node* next[alph];
    int when;
    int vcost[alph];
    int posmask[alph];
    bool end;
    node () { rep (i, alph) next[i] = 0; 
        when = -1;
        end = 0;
    }

    void add(char *input) {
        if (*input == 0) { end = 1; return; }
        int letter = *input - 'a';
        if (next[letter] == 0) next[letter] = new node();
        next[letter]->add(input + 1);
    }

    int eval(int id, char *input, int pos, int cost) {
        if (pos > maxlen) assert(0);
        if (cost >= bcost) return (int)1e9;
        if (when < id) { when = id; fo(i, 0, maxlen) { vcost[i] = (int)1e9; } }
        if (vcost[pos] > cost) { vcost[pos] = cost; posmask[pos] = -1; }
        if (posmask[pos] != -1 && posmask[pos] < (int)1e9) return posmask[pos];

        int result = (int)1e9;
        if (end) {
            checkmin(result, maxlen - pos);
            checkmin(bcost, cost + maxlen - pos);
        }
        char neletter = input[pos] - 'a';

        if (pos < maxlen && next[neletter])
            checkmin(result, +
                   next[neletter]->eval(id, input, pos + 1, cost));

        rep (i, alph) if (next[i])
        {
            if (pos < maxlen)
            checkmin(result, (i  != neletter) +
                   next[i]->eval(id, input, pos + 1, (i + 'a' != input[pos]) + cost));
            checkmin(bcost, cost + result);
        }
        rep (i, alph) if (next[i]) {
            checkmin(result, (1) +
                   next[i]->eval(id, input, pos, 1 + cost));
        }
        checkmin(bcost, cost + result);
        if (pos < maxlen)
            checkmin(result, 1 + eval(id, input, pos + 1, 1 + cost));
        checkmin(bcost, cost + result);
        return posmask[pos] = result;
    }
};

void _main() {
    node *root = new node();
    {
        //FILE *f = fopen("./twl06.txt", "r");
        FILE *f = fopen("/var/tmp/twl06.txt", "r");

        {
            while (fscanf(f, "%s", buf) == 1) {
                int len = strlen(buf);
                rep (i, len) buf[i] = tolower(buf[i]);
                root->add(buf);

                //db.push_back(buf);
            }
        }

        fclose(f);
    }

    {
        int result = 0;
        {
            int id = 0;
            while (scanf("%s", buf) == 1) {
                int k = strlen(buf);
                maxlen = k;

                bcost = (int)1e9;
                int tmp = root->eval(id, buf, 0, 0);
                db(buf<<" "<<tmp);
                result += tmp;
                id++;
            }
        }
        {
            printf("%d\n", result);
        }
    }


}

int main(int argc, char ** argv) {
    string p = "../gcj/source/" + string("") + argv[0][strlen(argv[0])-1];
    freopen(argv[1], "r", stdin);
    rep (i, argc) if (strcmp(argv[i], "s0") == 0) { freopen((p + "-small-0.in").c_str(),"r",stdin);freopen((p + "-small-0.out").c_str(),"w",stdout); }
    rep (i, argc) if (strcmp(argv[i], "s1") == 0) { freopen((p + "-small-1.in").c_str(),"r",stdin);freopen((p + "-small-1.out").c_str(),"w",stdout); }
    rep (i, argc) if (strcmp(argv[i], "s2") == 0) { freopen((p + "-small-2.in").c_str(),"r",stdin);freopen((p + "-small-2.out").c_str(),"w",stdout); }
    rep (i, argc) if (strcmp(argv[i], "l0") == 0) { freopen((p + "-large-0.in").c_str(),"r",stdin);freopen((p + "-large-0.out").c_str(),"w",stdout); }
    rep (i, argc) if (strcmp(argv[i], "q") == 0) cond = 1 << 30;
    db(argc);
    _main();
    return 0;
}
