#line 2 "CellRemoval.cpp"
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

int sum( map<int,vector<int>* > & kids, int del_cell, int root = -1 )
{
    cout<<"Travesing: "<<root<<endl;
    if( root == del_cell ) return 0;
    int ret = isMaped( kids, root ) ? 0 : 1;
    
    if( isMaped( kids, root ) ) for( int i = 0; i < kids[root]->size(); ++i ) ret += sum( kids, del_cell, (*kids[root])[i] );
    return ret;
}

void printMap( map<int,vector<int>* > & kids )
{
     FOREACH( el, kids )
     {
              cout<<el->first<<": ";
              for( int i = 0; i < el->second->size(); ++i )
              {
                   cout<<(*el->second)[i]<<", ";
               }
               cout<<endl;
     }
}

class CellRemoval 
{
	public:
	int cellsLeft(vector <int> parent, int deletedCell) 
	{
		map<int,vector<int> * > children;
		for( int i = 0; i < parent.size(); ++i )
		{
             if( !isMaped( children, parent[i] ) ) children[parent[i]] = new vector<int>();
             children[parent[i]]->push_back(i);
        }
        printMap( children );
        return sum( children, deletedCell );
	}
};


// Powered by FileEdit
