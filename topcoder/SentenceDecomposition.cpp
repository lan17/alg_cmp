#line 2 "SentenceDecomposition.cpp"
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

int INF = 1000000;

int swapz( const string & p_word, const string & valid_word )
{
    string s1, s2;
    s1 = p_word;
    s2 = valid_word;
    sort( ALL( s1 ) );
    sort( ALL( s2 ) );
    if( s1 != s2 ) return INF;
    int ret = 0;
    FOR( i, s1.size() )
    {
         if( p_word[i] != valid_word[i] ) ret++;
    }
    return ret;
}

void print2DV( vector<vector<int> > & v )
{
     FOREACH( ve, v )
     {
              FOREACH( n, *ve)
              {
                       cout<<*n<<" ";
              }
              cout<<endl;
     }
 }

class SentenceDecomposition 
{
	public:
	int decompose(string sentence, vector <string> validWords) 
	{
        
		vector< vector<int> > dp;
		FOR( i, sentence.size() + 1 )
		{
             dp.push_back( vector<int>( validWords.size()+1, INF ) );
         }
         FOR( i, validWords.size() + 1 )
         {
              dp[0][i] = 0;
          }
         FORR( i, 1, sentence.size()  )
         {
              dp[i][0] = INF;
          }
         
         FORR(  i1, 1, sentence.size() )
         {
              FORR( j1,1, validWords.size() )
              {
                    int i = i1 - 1;
                    int j = j1 - 1;
                    
                    int min_v = INF;
                    FORR( z, 0, validWords.size()  )
                    {
                          min_v = min( min_v, dp[i1][z] );
                    }
                    if( i1 - (int)validWords[j].size() >= 0 )
                    {
                        string word = sentence.substr( i1 - validWords[j].size(), validWords[j].size() );
                        int n = swapz( word, validWords[j]);
                        if( n != INF )
                        {
                            FORR( z, 0, validWords.size() )
                            {
                                  min_v = min( min_v, dp[i1 - (int)validWords[j].size()][z] + n );
                            }
                        }
                    }
                    dp[i1][j1]=min_v;
              }
          } 
          print2DV( dp );
          if( dp[sentence.size()][validWords.size()] == INF ) return -1;
          else return dp[sentence.size()][validWords.size()];
         
		
		
		
		/*
		vector<int> dp( sentence.size() + 1, INF );
		dp[0] = 0;
		for( int i = 1; i <= sentence.size(); ++i )
		{
             for( int j = 0; j < i; ++j )
             {
                  for( int k = 0; k < validWords.size(); ++k )
                  {
                       dp[i] = min( dp[i], dp[j] + swapz( sentence.substr( j, i -j ), validWords[k] ) );
                  }
             }
        }
        return dp[sentence.size()]==INF?-1:dp[sentence.size()];
		*/
	}
};


// Powered by FileEdit
