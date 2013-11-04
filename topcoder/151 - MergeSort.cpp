#include <vector>
#include <iostream>

using namespace std;

void printVector( vector< int > a )
{
     for( vector<int> ::iterator i = a.begin( ); i != a.end( ); ++i )
     {
          cout<<*i<<", ";
     }
     cout<<endl;
}

class MergeSort
{
      public:
             int num_comp;
             
             vector<int> mergeSort( vector<int> a )
             {
                         if( a.size( ) <= 1 ) { return a; }
                         vector< int > b, c;
                         int k = a.size( ) / 2;
                         vector<int>::iterator i = a.begin( );
                         b.assign( i, i + k );
                         c.assign( i + k, a.end( ) );
                         printVector( b );
                         printVector( c );
                         vector< int > sb, sc;
                         sb = mergeSort( b );
                         sc = mergeSort( c );
                         return merge( sb, sc );
             }
             
             vector<int> merge( vector<int> b, vector<int> c)
             {
                         vector< int > a;
                         while( b.size( ) != 0 && c.size( ) != 0 )
                         {
                                int first_b, first_c;
                                first_b = b[0];
                                first_c = c[0];
                                if( first_b == first_c )
                                {
                                    a.push_back( first_b );
                                    a.push_back( first_c );
                                    b.erase( b.begin( ) );
                                    c.erase( c.begin( ) );
                                }
                                if( first_b > first_c )
                                {
                                    a.push_back( first_c );
                                    c.erase( c.begin( ) );
                                }
                                if( first_b < first_c )
                                {
                                    a.push_back( first_b );
                                    b.erase( b.begin( ) );
                                }
                                num_comp++;
                         }
                         if( b.size( ) != 0 )
                         {
                             a.insert( a.end( ), b.begin( ), b.end( ) );
                         }
                         else
                         {
                             a.insert( a.end( ), c.begin( ), c.end( ) );
                         }
                         return a;
             }
             
             int howManyComparisons(vector <int> numbers)
             {
                 num_comp = 0;
                 mergeSort( numbers );
                 return num_comp;
                 
             }
};

