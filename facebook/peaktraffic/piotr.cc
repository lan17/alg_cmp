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
#define VI vector<int>
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

char buf[65535];
char buf2[65535];

map <string, int> e2id;
map <int, int> id2ord;
map <int, string> ord2e;

int getid(string input) {
    int e2sz = e2id.size(); // c++ bug
    if (e2id.count(input) == 0) return e2id[input] = e2sz;
    return e2id[input];
}


vector<set<int> > ed;
vector<vector<int> > edge;

set<vector<int> > db;
vector<vector<int> > result;


bool check(int j, int it) {
    int k = lower_bound(all(edge[j]), it) - edge[j].begin();;
    return k < (int)edge[j].size() && edge[j][k] == it;
}

int n;
set<vector<int> > vis;
set<ll> vis2;
const int sz = 65536;
ll ha[sz];

void solve(vector<int> &cur, int next, ll cha) {
    if (vis2.insert(cha).second == 0) return;
    bool can = 0;
    
    if (cur.size() >= 1) {
        //int i = lower_bound(all(edge[cur[0]]), next) - edge[cur[0]].begin();
        int i = next;

        for (;i<(int)edge[cur[0]].size();i++) {
            int j = edge[cur[0]][i];
            bool ok = 1;
            fore (it, cur) {
                ok &= *it != j;
                ok &= check(j, *it);
                ok &= check(*it, j);
                if (!ok) break;
            }
            if (ok) {
                can = 1;
                cur.push_back(j);
                solve(cur, i + 1, cha + ha[j]);
                cur.pop_back();
            }

        }

        i = 0;
        for (;i<next&&i<(int)edge[cur[0]].size();i++) {
            int j = edge[cur[0]][i];
            bool ok = 1;
            fore (it, cur) {
                ok &= *it != j;
                ok &= check(j, *it);
                ok &= check(*it, j);
                if (!ok) break;
            }
            if (ok) {
                can = 1;
                break;
            }

        }

    }
    else {
        fo (j, next, n - 1) {
            db(j<<" "<<n<<" "<<result.size());
            cur.push_back(j);
            solve(cur, 0, cha + ha[j]);
            cur.pop_back();
            can = 1;
        }
    }

    if (can == 0  && cur.size() >= 3) {
        result.push_back(cur);
        fore (it, cur) fore (jt, cur) {
            assert(*it == *jt || check(*it, *jt));
        }

    }
     
}



void _main() {
    ha[0] = 1; fo (i , 1, sz-1) ha[i] = ha[i-1] * ((int)2e9+11);
    db("");
    int m = 0;
    while (scanf("%s", buf) == 1) {
        m++;
        bool ok = 0;
        for (int i = strlen(buf) - 1; i >= 0; i--) ok |= buf[i] == '@';
        if (!ok) continue;

        scanf("%s", buf2);
        ok = 0;
        for (int i = strlen(buf2) - 1; i >= 0; i--) ok |= buf2[i] == '@';
        assert(ok);

        int le = getid(buf), ri = getid(buf2);
        ed.resize(e2id.size());
        ed[le].insert(ri);
    }
    db(m);
    db("");

    n = e2id.size();
    int cnt = 0;
    fore (it, e2id) { id2ord[it->second] = cnt; ord2e[cnt] = it->first;
        cnt++;
    }

    db("");
    ed.resize(n);
    edge.resize(n);
    db("");

    rep (i, n) fore(it, ed[i]) 
           if (ed[*it].count(i)) edge[id2ord[i]].push_back(id2ord[*it]);
    rep (i, n) sort(all(edge[i]));
    rep (i, n) edge[i].resize(unique(all(edge[i])) - edge[i].begin());
    //rep (i, n) edge[i].insert(i);;

    vector<int> xx;
    solve(xx, 0, 0);
    //sort(all(result));
    //result.resize(unique(all(result)) - result.begin());
    db(result.size());
    rep (i, (int)result.size()) {
        rep (j, (int)result[i].size()) {
            if (j) printf(", ");
            printf("%s", ord2e[result[i][j]].c_str());
        }
        printf("\n");
    }
}

int main(int argc, char ** argv) {
    string p = "../gcj/source/" + string("") + argv[0][strlen(argv[0])-1];
    if (argc >= 2 && strcmp(argv[1], "q") != 0) { freopen(argv[1],"r",stdin);}

    rep (i, argc) if (strcmp(argv[i], "1n") == 0) { freopen("1.in","r",stdin);}
    rep (i, argc) if (strcmp(argv[i], "2n") == 0) { freopen("2.in","r",stdin);}
    rep (i, argc) if (strcmp(argv[i], "3n") == 0) { freopen("3.in","r",stdin);}
    rep (i, argc) if (strcmp(argv[i], "4n") == 0) { freopen("4.in","r",stdin);}
    rep (i, argc) if (strcmp(argv[i], "5n") == 0) { freopen("5.in","r",stdin);}

    rep (i, argc) if (strcmp(argv[i], "s0") == 0) { freopen((p + "-small-0.in").c_str(),"r",stdin);freopen((p + "-small-0.out").c_str(),"w",stdout); }
    rep (i, argc) if (strcmp(argv[i], "s1") == 0) { freopen((p + "-small-1.in").c_str(),"r",stdin);freopen((p + "-small-1.out").c_str(),"w",stdout); }
    rep (i, argc) if (strcmp(argv[i], "s2") == 0) { freopen((p + "-small-2.in").c_str(),"r",stdin);freopen((p + "-small-2.out").c_str(),"w",stdout); }
    rep (i, argc) if (strcmp(argv[i], "l0") == 0) { freopen((p + "-large-0.in").c_str(),"r",stdin);freopen((p + "-large-0.out").c_str(),"w",stdout); }
    rep (i, argc) if (strcmp(argv[i], "q") == 0) cond = 1 << 30;
    db(argc);
    _main();
    return 0;
}