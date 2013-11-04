%{
/* C code to be copied verbatim */
#include <stdio.h>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>

#define NUM 1
#define CORRECT 2
#define NCORRECT 3

using namespace std;

string ret_str;
int line_num = 1;

%}

%option noyywrap

%%
    /*** Rules section ***/
[0-9]* {
		ret_str = yytext;
		return NUM;
		}
["one"+"out"+"output"+"puton"+"in"+"input"+"one"]* {
	ret_str = yytext;
	return CORRECT;
}
			 
[ \t\n\f\r] { 
			// if the program sees a new line, then it means that one line comment must end, and that line_num must be incremented.
			if( yytext[0] == '\n' ) { line_num++; }
			//printLogic( );
		   }

.     {
		// everything else.  tells the main the char wasnt recognized.
		ret_str = yytext;
		return NCORRECT; 
	   }

%%
/*** C Code section ***/

int main(void)
{
	int n,token;
	//cout<<"STARTING"<<endl;
	while( token = yylex( ) )
	{
		//cout<<ret_str<<endl;
		if( token == NUM )
		{
			n = atoi( ret_str.c_str( ) );
		}
		if( token == CORRECT )
		{
			cout<<"YES - "<<ret_str<<endl;
		}
		else if( token == NCORRECT ) cout<<"NO - '"<<ret_str<<"'"<<endl; 

	}
	//cout<<token<<endl;
	//cout<<"Done parsing the file ("<<line_num<<" lines)... going to sleep"<<endl;
}
