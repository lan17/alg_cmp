#line 2 "ContiguousCacheEasy.cpp"
#include <string>
#include <vector>
#include <map>
#include <iostream>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

void addToPair( pair<int, int > & p, int a )
{
     p.first += a;
     p.second +=a;
 }
 
int pairDiff( const pair<int,int> & p1, const pair<int,int> & p2)
{
    
    if( p2.first > p1.second ) return p2.second-p2.first + 1;
    if( p2.second < p1.first ) return p2.second-p2.first + 1;
    if( p2.first >= p1.first && p2.first <= p1.second )
    {
        return p2.second - p1.second;
    } 
    if( p2.second <= p1.second && p2.second >= p1.first )
    {
        return p1.first - p2.first;
    }
     
}


class ContiguousCacheEasy 
{
	public:
	int bytesRead(int n, int k, vector <int> addresses) 
	{
        //vector<bool> byte_range (n, false );
        pair< int, int > range, old_range;
        range.first = 0;
        range.second = k - 1;
		int ret = 0;
        FOREACH( el, addresses )
		{
                 old_range = range;
                 
                 cout<<"=========="<<endl;
                 cout<<old_range.first<<","<<old_range.second<<endl;
                 
                 
                 if( range.first <= *el && *el <= range.second ) continue;
                 if( range.second < *el )
                 {
                     int correction = *el - range.second;
                     //ret += correction;
                     addToPair( range, correction );
                     cout<<range.first<<","<<range.second<<endl;
                     cout<<pairDiff( old_range, range )<<endl;
                     ret += pairDiff( old_range, range );
                     continue;
                 }
                 if( range.first > *el )
                 {
                     int correction = range.first - *el;
                     //ret += correction;
                     addToPair( range, -1 *correction );
                     cout<<range.first<<","<<range.second<<endl;
                     cout<<pairDiff( old_range, range )<<endl;
                     ret += pairDiff( old_range, range );
                     continue;
                 }
        }
        cout<<range.first<<","<<range.second<<endl;
        return ret;
	}
};
