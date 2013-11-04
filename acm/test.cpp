#include <iostream>
using namespace std;

struct foo
{
       int bar;
};

void func( foo ** a )
{
     //*a = new foo();
     //cout<<*a;
 }


int main()
{
    foo ** a;
    a = (foo**) malloc( 489789);
    *a= new foo();
    (*a)->bar=5;
    //func( a );
    cout<<(*a)->bar;
    
    int asdf;
    cin>>asdf;
    
}
