 #include <iostream> 
 #include <string>
   #define FOR( i, n ) for( int (i) = 0; (i) < (n); ++(i) )
   #define FORR( i, n, m ) for(int (i) = (n); (i) <= (m); ++(i) )
 using namespace std; 
   
 bool test(string & start, int i =0);
 bool compare(const string & c1, const string & c2, int i ); 
   
 int main(int argc, char *argv[])
 {
	int n;
	cin>>n;
	if( cin.peek( ) == '\n' ) cin.ignore( );
	FOR( i, n )
	{
		string line;
		getline( cin, line );
		if( test( line ) ) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
 }
 
 bool test(string & str, int start)
 {
   if ( start == str.size( ) )
     return true; 
   
   bool r1 = false, r2 = false, r3 = false, r4 = false, r5 = false, r6 = false; 
   
   if (compare(str, "output", start))
     r1 = test(str, start + 6); 
   
   if (compare(str, "in", start))
     r2 = test(str, start + 2); 
   
   if (compare(str, "puton", start))
     r3 = test(str, start + 5); 
   
   if (compare(str, "out",start))
     r4 = test(str, start + 3);
 
 if (compare(str,"input",start))
     r5 = test(str, start + 5); 
   
   if (compare(str, "one", start))
     r6 = test(str, start + 3); 
   
 
   return r1 || r2 || r3 || r4 || r5 || r6; 
   
 } 
   
 bool compare(const string & c1, const string & c2, int i)
 {
   FORR( j, i, c2.size( ) ){  if( c1[j] != c2[j-i] ) return false; }
   
   
   return true;
 } 
 
