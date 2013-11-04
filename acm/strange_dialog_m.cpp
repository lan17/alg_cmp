#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

#define vecs vector< string > 
#define veci vector< int >
#define vecsi vector<string>::iterator
#define vecii vector<int>::iterator

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
//#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;


int _LEV_NUM_STATES = 21;
int _LEV_NUM_LETTERS = 7;
int _LEV_INITIAL = 0;
int _LEV_MCI( char & c )
{
    switch( c )
    {
            case 'e': return 0;
            case 'i': return 1;
            case 'n': return 2;
            case 'o': return 3;
            case 'p': return 4;
            case 't': return 5;
            case 'u': return 6;
            default: return -1;
        }
}
int _LEV_DFA[21][7] = { { -1, 3, -1, 1, 2, -1, -1 }, { -1, -1, 10, -1, -1, -1, 9 }, { -1, -1, -1, -1, -1, -1, 4 }, { -1, -1, 5, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, 6, -1 }, { -1, 3, -1, 1, 7, -1, -1 }, { -1, -1, -1, 8, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, 12 }, { -1, -1, 13, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, 14, -1 }, { 11, -1, -1, -1, -1, -1, -1 }, { -1, 3, -1, 1, 2, -1, -1 }, { -1, -1, -1, -1, -1, 15, -1 }, { -1, 3, -1, 1, 2, -1, -1 }, { -1, 3, -1, 1, 16, -1, -1 }, { -1, 3, -1, 17, 2, -1, -1 }, { -1, -1, -1, -1, -1, -1, 18 }, { -1, -1, 19, -1, -1, -1, 9 }, { -1, -1, -1, -1, -1, 20, -1 }, { 11, 3, -1, 1, 2, -1, -1 }, { -1, 3, -1, 17, 2, -1, -1 } };
bool _LEV_VALID_STATES[] = { 0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,1,0,0,0,1,1};


int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	if( cin.peek( ) == '\n' ) cin.ignore( );
	FOR( i, n )
	{
         char c;
         int state = _LEV_INITIAL;
         bool dc = true;
         while( c = getc( stdin ) )
         {
                if( c == '\n' || c < 97 || c > 122  ) break;
                int l = _LEV_MCI( c );
                if( l == -1 ) { cout<<"NO"<<endl; dc=false; break; }
                state = _LEV_DFA[state][l];
                if( state == -1 ) { cout<<"NO"<<endl; dc=false; break; }
         }
         if( !dc ) { while( c = getc( stdin ) ) {if(c=='\n')break;} } //consume rest of line.
         //cout<<state<<" "<<_LEV_VALID_STATES[state]<<endl;
         if( dc ){
         if( _LEV_VALID_STATES[ state ] ) cout<<"YES"<<endl;
         else cout<<"NO"<<endl;
         }
              
	}
	
	
	return 0;
}
