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


template <class T>
void print_vec(const vector<T> & a)
{
	for( size_t i = 0; i < a.size(); ++i )
	{
		cout<<a[i]<<", ";
	}
	cout<<endl;
}

class MagicCandy {
	public:
	int whichOne(int n) 
	{
		/*
		veci nums(n);
		for( size_t i = 0; i < n; ++i )
		{
			nums[i] = i+1;
		}

		set<size_t> sqrs;
		for( size_t i = 1; i*i <=n ; ++i )
		{
			sqrs.insert( i*i );
		}

		while( nums.size() > 1 )
		{
			print_vec(nums);
			set<int> tdl;
			for( size_t i = 0; i < nums.size(); ++i )
			{
				if( IN( sqrs, i+1) )
				{
					tdl.insert( nums[i] );
				}
			}
			veci nnums;
			for( size_t i = 0; i < nums.size(); ++i )
			{
				if( ! IN(tdl,nums[i]))
					nnums.push_back(nums[i]);
			}
			nums = nnums;
		}
		*/

		int a = 1;
		int b = 1;
		int tt = 1;
		int cc = 0;
		while( a < n )
		{
			cout<<a<<endl;
			b = a;
			a += tt;
			++cc;
			if( cc == 2 )
			{
				++tt;
				cc = 0;
			}

		}
		if( a == n ) return a;
		return b;
		
	}
};
