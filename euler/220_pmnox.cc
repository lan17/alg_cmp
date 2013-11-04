#include <iostream>
#include <ctime>
#include <string>
#include <complex>
#include <cstdio>
 
 
#define ll long long
using namespace std;
 
// 3 37
// 10 14
#define cll complex<ll>
#define rep(i,x) for (int i = (0); (i) < (x); (i)++)
 
string data[2] = {"aRbFR", "LFaLb" };
 
cll mul[4] = { cll(1, 0), cll(0, -1), cll(-1, 0), cll(0, 1) };
 
ll steps[2][60];
cll vect[2][60];
int dir[2][60];
 
void go(int i, cll ve, int dd, int typ, ll st) {
        if (i == 0) return;
        rep (g, data[typ].size()) 
        {
                char x = data[typ][g];
                if (x == 'R') dd = (dd+1) % 4;
                else if (x == 'L') dd = (dd+3) % 4;
                else if (x == 'F') 
                {
                        st--;
                        ve += cll(0,1) * mul[dd];
                        if (st == 0) 
                        {
                                cout << "QQ =  " << ve << endl;
                                return;
                        }
                }
                else if (x == 'a') 
                {
                        if (st <= steps[0][i-1]) 
                        {
                                go(i - 1, ve, dd, 0, st);
                                return;
                        }
                        ve += vect[0][i-1] * mul[dd];
                        st -= steps[0][i-1];
                        dd = (dd + dir[0][i-1]) % 4;
                }
                else if (x == 'b') 
                {
                        if (st <= steps[0][i-1]) 
                        {
                                go(i - 1, ve, dd, 1, st);
                                return;
                        }
                        ve += vect[1][i-1] * mul[dd];
                        st -= steps[1][i-1];
                        dd = (dd + dir[1][i-1]) % 4;
                }
        }
}
 
int main() {
        rep (i, 60) 
        rep (typ, 2) 
        {
                ll &st = steps[typ][i] = 0;
                cll &ve = vect[typ][i] = cll(0,0);
                int &dd = dir[typ][i] = 0;
                if (i) 
                {
                        rep (g, data[typ].size()) 
                        {
                                char x = data[typ][g];
                                if (x == 'R') dd = (dd+1) % 4;
                                else if (x == 'L') dd = (dd+3) % 4;
                                else if (x == 'F') 
                                {
                                        st++;
                                        ve += cll(0,1) * mul[dd];
                                }
                                else if (x == 'a') 
                                {
                                        ve += vect[0][i-1] * mul[dd];
                                        st += steps[0][i-1];
                                        dd = (dd + dir[0][i-1]) % 4;
                                }
                                else if (x == 'b') 
                                {
                                        ve += vect[1][i-1] * mul[dd];
                                        st += steps[1][i-1];
                                        dd = (dd + dir[1][i-1]) % 4;
                                }
                        }
                }
                steps[typ][i] = min((ll)1e15, steps[typ][i]);
        }
        go(50, cll(0,1), 0, 0, (ll)1e12 - 1);
 
        return 0;
}
