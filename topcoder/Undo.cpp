#line 2 "Undo.cpp"
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

#define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) ) 
#define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) ) 
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();(_it)++) 
#define ALL(x) (x).begin(),(x).end() 

#define isMaped( m, element ) ((m).find( (element) ) != (m).end()) 
#define addFront( x, y ) (x).insert( (x).begin(), (y) ) 

using namespace std;

int getPrevTime( map<int,string> & words, int t )
{
    FOREACH( p, words )
    {
             map<int,string>::iterator i = ++p;
             p--;
             if( i != words.end() )
             {
                 if( p->first < t && i->first >= t ) 
                 {
                     cout<<p->first<<" "<<i->first<<" "<<t<<endl;
                     return p->first;
                 }
             }
             else
             {
                 cout<<p->first<<" "<<t<<endl;
                 return p->first;
             }
    }
}

class Undo  
{
	public:
	string getText(vector <string> commands, vector <int> time) 
	{
		map<int,string> words;
		words[0] = "";
		FOR( i, time.size() )
		{
             words[time[i]] = "";
         }
		FOR( i, time.size() )
		{
             string command = commands[i].substr( 0, commands[i].find( ' ' ) );
             if( command == "type" )
             {
                          char t = commands[i][5];
                          words[time[i]] = words[getPrevTime(words,time[i])];
                          words[time[i]].push_back( t );
             }
             if( command == "undo" )
             {
                         string t = commands[i].substr( 4 );
                         int steps = atoi( t.c_str() );
                         words[time[i]] = words[getPrevTime(words,time[i]-steps)];
             }
         }
         return words[time[time.size()-1]];
	}
};
