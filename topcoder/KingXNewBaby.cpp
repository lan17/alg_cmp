#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>

using namespace std;



class KingXNewBaby
{
	public:
	string isValid(string name)
	{
		if(name.size() != 8 ) return "NO";
		string vowel = "aeiou";
		int vc = 0;
		char v = 'z';
		for( int i = 0; i < name.size(); ++i )
		{
			char t = name[i];
			if( vowel.find(t) != string::npos )
			{
				vc++;
				if( v != 'z' && v != t )
					return "NO";
				v = t;
			}
		}
		if( vc != 2 ) return "NO";
		return "YES";


	}
};
