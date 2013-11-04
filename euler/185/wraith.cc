#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
//#include <tchar.h>

using namespace std;

struct Entry
{
	const char* num;
	int correct;
};
 
const Entry INPUT[] = {
	{"3847439647293047", 1},
 
	{"2321386104303845", 0},
 
	{"8157356344118483", 1},
	{"3174248439465858", 1},
	{"4895722652190306", 1},
	{"6375711915077050", 1},
	{"6913859173121360", 1},
 
 
	{"5616185650518293", 2},	
	{"4513559094146117", 2},
	{"2615250744386899", 2},
	{"6442889055042768", 2},
	{"2326509471271448", 2},
	{"5251583379644322", 2},
	{"2659862637316867", 2},
 
	{"8690095851526254", 3},
	{"7890971548908067", 3},
	{"5855462940810587", 3},
	{"9742855507068353", 3},
	{"4296849643607543", 3},
	{"1748270476758276", 3},
	{"3041631117224635", 3},
	{"1841236454324589", 3},	
};
 
const int LEN = 16;
const int ILEN = 22;
 
vector< vector< vector<int> > > cmb;
 
void fill_cmb(int pos, int level, vector<int>& ar)
{
	if(level == -1)
		return;
 
	for(int i=pos; i<LEN; ++i)
	{
		ar[level] = i;
		if(level == 0)
		{
			cmb.back().push_back(ar);
			reverse(cmb.back().back().begin(), cmb.back().back().end());
		}
		fill_cmb(i+1, level-1, ar);
	}
}
 
int maxlevel;
 
void solve(const char* num, int level)
{
	const int ns = int(std::count(num, num+LEN, 'n'));
 
	if(level == ILEN)
	{
		//here 464026157184n533 was found. 
		//I checked manually and found out that n could only be 9
		cout << "\tfound something: " << num << endl;
		if(!ns)
		{
			cout << "solution found:\n\t" << num << endl;
			exit(0);
		}
 
		return;
	}
 
	const char* check = INPUT[level].num;
	int correct = INPUT[level].correct;
 
	for(int i=0; i<LEN; ++i)
	{
		correct -= check[i] == num[i];
		if(correct < 0) return;			
	}
 
	if(correct == 0)
	{
		solve(num, level+1);
		return;
	}
 
	if(ns < correct)
		return;
 
	char newnum[LEN+1];
	for(size_t i=0; i<cmb[correct].size(); ++i)
	{		
		strcpy(newnum, num);
		const vector<int>& test = cmb[correct][i];
 
		size_t t;
		for(t=0; t<test.size(); ++t)
		{
			int elem = test[t];
			if(newnum[elem]!='n')
				break;
 
			int l;
			for(l=0; l<level; ++l)
			{
				if(INPUT[l].num[elem] == check[elem])
					break;
			}
 
			if(l != level)
				break;
 
			newnum[elem] = check[elem];
		}
 
		if(t==test.size())
		{
			solve(newnum, level+1);
		}
	}
 
}
 
int main()
{
	cmb.push_back(vector< vector<int> >());
	for(int i=0; i<3; ++i)
	{
		vector<int> dummy(i+1);
		cmb.push_back(vector< vector<int> >());
		fill_cmb(0, i, dummy);
	}
 
	string in(LEN, 'n');
 
	solve(in.c_str(), 0);
 
	return 0;
}
