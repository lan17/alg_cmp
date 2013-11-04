#include <map>
#include <iostream>
#include <fstream>

#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++)

using namespace std;

unsigned __int64 fib( unsigned __int64 n, map<unsigned __int64,unsigned __int64> & table )
{
    if( n == 0 ) return 0;
    if( n == 1 ) return 1;
    if( table.find( n ) == table.end( ) ) table[n] = fib( n-1, table ) + fib( n -2, table );
    return table[n];
}

int main( int argc, char ** argv )
{
    unsigned __int64 n = atoi( argv[1] );
    map<unsigned __int64,unsigned __int64> table;
    cout<<n<<"th fibonacci number is ";
    cout<<fib( n, table )<<endl;
    ofstream ofs( "fib.txt" );
    FOREACH( num, table )
    {
             ofs<<num->second<<" ";
    }
    ofs.close( );
    return 0;
}
