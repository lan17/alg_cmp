#include <vector>

using namespace std;

int findIndex( vector<int> & v, int i, int z = -1 )
{
    for( int k = 0; k < v.size( ); ++k )
    {
         if( v[k] == i && k >z ) { return k;  }
    }
    return -1;
}

class PowerOutage
{
      public:
             
             int computeLength( vector <int> & fromJunction, vector <int> & toJunction, vector <int> & ductLength, int leaf )
             {
                 int z = leaf;
                 int sum = 0;
                 while( z != 0 )
                 {
                        int i = findIndex( toJunction, z );
                        sum += ductLength[ i ];
                        z = fromJunction[i];
                 }
                 return sum;
             }
             
             vector<int> computeLeafNodes( vector <int> & fromJunction, vector <int> & toJunction )
             {
                         vector<int> nodes;
                         for( int i = 0; i < toJunction.size( ); ++i )
                         {
                              if( findIndex( fromJunction, toJunction[i] ) == -1 )
                              {
                                  nodes.push_back( toJunction[i] );
                              }
                         }
                         return nodes;
                         
             }
             
             int estimateTimeOut(vector <int> fromJunction, vector <int> toJunction, vector <int> ductLength)
             {
                 int sum = 0;
                 for( int i = 0; i < ductLength.size( ); ++i )
                 {
                      sum += ductLength[i];
                 }
                 int max = 0;
                 vector<int> leafs = computeLeafNodes( fromJunction, toJunction );
                 for( int i = 0; i < leafs.size( ); ++i )
                 {
                      int t = computeLength( fromJunction, toJunction, ductLength, leafs[i] );
                      if( t > max  ) { max = t; }
                 }
                 return sum*2-max;
                 
                 
             }
};
