#include <iostream>
#include <string>

using namespace std;

template <class T>
struct node
{
       T data;
       node * left;
       node * right;
       
       node()
       {
             left = right = NULL;
       }
       
       node( T & el )
       {
             data = el;
             left = right = NULL;
       }
       
       void add( T & el )
       {
            if( el < data && left != NULL ) left->add( el );
            if( el >= data && right != NULL ) right->add( el );
            if( el < data && left == NULL ) left = new node( el );
            if( el >= data && right == NULL ) right = new node( el );
       }
       
       void print_in_order()
       {
            if( left != NULL ) left->print_in_order();
            cout<<data<<" ";
            if( right != NULL ) right->print_in_order();
        }
};

int main( int argc, char ** argv )
{
    string input;
    getline( cin, input );
    if( input.size() == 0 ) return 0;
    
    node<char> * tree = new node<char>();
    tree->data = input[0];
    for( size_t i = 1; i < input.size(); ++i )
    {
         tree->add( input[i] );
     }
    tree->print_in_order();
    
    
}
