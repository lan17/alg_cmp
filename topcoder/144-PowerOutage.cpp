#include <vector>
#include <map>
#include <iostream>

#define vecii vector<int>::iterator

using namespace std;

void printVector( vector< int > a )
{
     for( vector<int> ::iterator i = a.begin( ); i != a.end( ); ++i )
     {
          cout<<*i<<", ";
     }
     cout<<endl;
}

struct duct
{
       int num;
       int length;
       vector<duct> children;
};



int findIndex( vector<int> & v, int i, int z = -1 )
{
    for( int k = 0; k < v.size( ); ++k )
    {
         if( v[k] == i && k >z ) { return k;  }
    }
    return -1;
}

vector<int> findAll( vector<int> & v, int i )
{
            vector<int> ret;
            cout<<"Finding All for "<<i<<endl;
            int z = -1;
            while( 1 )
            {
                   z = findIndex( v, i, z );
                   if( z == -1 ) { return ret; }
                   //ut<<"\tfound "<<z<<endl;
                   ret.push_back( z );
            }
            return ret;
}

class PowerOutage
{
      public:
             
             void makeTree( vector <int> & fromJunction, vector <int> & toJunction, vector <int> & ductLength, duct & root )
             {
                  // find all ducts that cur node is a root of
                  vector< int > kids_index = findAll( fromJunction, root.num );
                  cout<<"Found - "; printVector( kids_index );
                  // if there are no ducts from cur junction then our job is done.
                  if( kids_index.size( ) == 0 ) { return; }
                  // if not create all children
                  for( int i = 0; i < kids_index.size( ); ++i )
                  {
                       duct tmp;
                       tmp.length = root.length + ductLength[ kids_index[i] ];
                       tmp.num = toJunction[ kids_index[i] ];
                       root.children.push_back( tmp );
                  }
                  // now recursively contrsuct subtrees for each child
                  for( int i = 0; i < root.children.size( ); ++i )
                  {
                       makeTree( fromJunction, toJunction, ductLength, root.children[i] );
                  }
                       
             }
             
             void computeLengths( duct & root, vector<int> & lengths )
             {
                  if( root.children.size( ) == 0 ) { lengths.push_back( root.length ); return; }
                  for( int i = 0; i < root.children.size( ); ++i )
                  {
                       computeLengths( root.children[i], lengths );
                  }
                  
              }
             
             
             int estimateTimeOut(vector <int> fromJunction, vector <int> toJunction, vector <int> ductLength)
             {
                 duct root;
                 root.num = 0;
                 root.length = 0;
                 cout<<"making tree"<<endl;
                 makeTree( fromJunction, toJunction, ductLength, root );
                 
                 int sum = 0;
                 int max = 0;
                 vector< int > lengths;
                 computeLengths( root, lengths );
                 for( int i = 0; i < lengths.size( ); ++i )
                 {
                      sum += lengths[i];
                      if( max < lengths[i] ){ max = lengths[i]; }
                 }
                 return sum*2 - max;
                 
                 
             }
};

