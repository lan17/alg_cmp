 #include <iostream> 
 #include <string>
   #define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
 using namespace std; 
   
 bool test(char *start);
 bool compare(const char *c1, const char *c2); 
   
 int main(int argc, char *argv[])
 {
	int n;
	cin>>n;
	if( cin.peek( ) == '\n' ) cin.ignore( );
	FOR( i, n )
	{
		char * line;
		
		cin>>line;
		if( test( line ) ) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
 }
 
 bool test(char *start)
 {
   if (*start == 0)
     return true; 
   
   bool r1 = false, r2 = false, r3 = false, r4 = false, r5 = false, r6 = false; 
   
   if (compare(start, "output"))
     r1 = test(start + 6); 
   
   if (compare(start, "in"))
     r2 = test(start + 2); 
   
   if (compare(start, "puton"))
     r3 = test(start + 5); 
   
   if (compare(start, "out"))
     r4 = test(start + 3);
 
 if (compare(start, "input"))
     r5 = test(start + 5); 
   
   if (compare(start, "one"))
     r6 = test(start + 3); 
   
 
   return r1 || r2 || r3 || r4 || r5 || r6; 
   
 } 
   
 bool compare(const char *c1, const char *c2)
 {
   for (int i=0; c2[i] != 0; i++)
     {
       if (c1[i] != c2[i])
         return false;
     }
   return true;
 } 
 
