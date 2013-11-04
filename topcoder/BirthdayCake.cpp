#line 2 "BirthdayCake.cpp"
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

std::vector<std::string> expand( const std::string & input, char delimiter )
{
	std::vector<std::string> out;
     size_t begin = 0;
     size_t i;
     for( i = 0; i < input.length( ); i++ )
     {
          if( i > 0 && input[i] == delimiter && input[i-1] != delimiter ) 
          { 
              out.push_back( input.substr( begin, i - begin ) ); 
              begin = i+1 ;
          }
          else
          {
              if( input[i] == delimiter ){ begin = i+1; }
          }
     }
     if( begin < i )
     {
         out.push_back( input.substr( begin ) );
     }
     return out;
}

class BirthdayCake 
{
	public:
	int howManyFriends(vector <string> availableFruits, vector <string> friendsDislikings, int K) 
	{
		map<string,int> fruitDislikes;
		map<string,vector<int>*> fruitDislikes_people;
		FOREACH( fruit, availableFruits )
		{
                 fruitDislikes[*fruit] = 0;
                 fruitDislikes_people[*fruit] = new vector<int>();
        }
        FOREACH( fruit, friendsDislikings )
        {
                 fruitDislikes_people[*fruit] = new vector<int>();
        }
		FOR( i, friendsDislikings.size() )
		{
                 vector<string> fruitz = expand( friendsDislikings[i], ' ' );
                 FOREACH( fruit, fruitz )
                 {
                          fruitDislikes[*fruit] += 1;
                          fruitDislikes_people[*fruit]->push_back( i );
                 }
        }
        vector<bool> people( friendsDislikings.size(), true );
        FOR( i, K )
        {
             string min_flavor;
             int min_people = 1<<29;
             FOREACH( fruit, fruitDislikes )
             {
                      if( fruit->second < min_people )
                      {
                          min_flavor = fruit->first;
                          min_people = fruit->second;
                      }
             }
             FOREACH( person, *fruitDislikes_people[min_flavor] )
             {
                      people[*person] = false;
             }
             FOREACH( fruit, availableFruits )
		     {
                 fruitDislikes[*fruit] = 0;
                 //fruitDislikes_people[*fruit] = new vector<int>();
                  }
             FOR( i, friendsDislikings.size() )
             {
                 if( !people[i] ) continue;
                 vector<string> fruitz = expand( friendsDislikings[i], ' ' );
                 FOREACH( fruit, fruitz )
                 {
                          fruitDislikes[*fruit] += 1;
                          fruitDislikes_people[*fruit]->push_back( i );
                 }
              }

             fruitDislikes[min_flavor] = 500;
        }
        int ret = 0;
        FOR( i, people.size() )
        {
             if( people[i] ) ret++;
        }
        return ret;
	}
};
