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

int print_dbg = 1;

#define d_print(x) { if(print_dbg){  cerr << __LINE__ << " " << #x << " = " << x << endl; cerr.flush(); } }

typedef vector<string> vecs;
typedef vector<int> veci;
typedef unsigned long long ull;
typedef long long ll;

#define ALL(x) (x).begin(), (x).end()
#define IN(x,y) ((x).find((y)) != (x).end())
#define FOREACH(_it,_l) for(__typeof((_l).begin()) _it=((_l).begin());(_it)!=(_l).end();++(_it))

vector<vector<int> > intersectsMem(100, vector<int>(100, -1 ));

struct Eel
{
	int index, start, end;
	Eel( int i, int start, int end ):index(i),start(start),end(end){}

	// do they intersect
	bool intersects( const Eel & eel ) const
	{
		int & answer = intersectsMem[index][eel.index];
		if( answer != -1 )
			return answer == 0 ? false : true;
		bool ret = false;
		ret |= start >= eel.start && start <= eel.end;
		ret |= end >= eel.start && end <= eel.end;
		ret |= eel.start >= start && eel.start <= end;
		ret |= eel.end >= start && eel.end <= end;
		answer = ret ? 1 : 0;
		intersectsMem[eel.index][index] = answer;
		return ret;
	}

	bool operator < (const Eel & eel ) const
	{
		return index < eel.index;
	}

	bool operator == (const Eel & eel ) const
	{
		return index == eel.index;
	}

};

ostream & operator << (ostream & os, const Eel & eel )
{
	//os<<"eel:["<<eel.index<<": "<<eel.start<<","<<eel.end<<"]";
	os<<eel.index;
	return os;
}

ostream & operator << ( ostream & os, const set<Eel> & eels )
{
	os<<"eels: { ";
	FOREACH( eel, eels  )
	{
		os<<*eel<<", ";
	}
	os<<"}";
	return os;
}

// get maximum number of eels we can fit given that kth eel MUST be included.
set<Eel> findMaxClique( const set<Eel> & eels, set<Eel> & klik )
{
	set<Eel> ret = klik;
	//d_print("==========");
	//d_print(klik);
	FOREACH( vEel, eels )
	{
		if( IN(klik,*vEel)) continue;
		bool good = true;
		FOREACH( eel, klik )
		{
			if(! eel->intersects(*vEel))
			{
				good = false;
				break;
			}
		}
		// MUST INVESTIGATE
		if( good )
		{

			klik.insert(*vEel);
			//d_print(*vEel);
			//d_print(newClique);

			set<Eel> sEel = findMaxClique(eels, klik );
			if( sEel.size() >= ret.size() )
				ret = sEel;
			klik.erase(*vEel);
		}
	}
	return ret;
}

class EelAndRabbit
{
	public:
	int getmax(vector <int> l, vector <int> t)
	{
		vector<int> nums;
		for( int i = 0; i < l.size(); ++i )
		{
			nums.push_back(t[i]);
			nums.push_back(t[i]+l[i]);
		}
		int best = 1;
		sort(ALL(nums));
		for( int i = 0; i < nums.size(); ++i)
		{
			for( int j = 0; j < i; ++j )
			{
				int count = 0;
				for( int k = 0; k < l.size(); ++k )
				{
					int start = t[k];
					int end = t[k] + l[k];
					if( ( start <= nums[i] && end >= nums[i] ) || (start <= nums[j] && end >= nums[j]) )
						++count;

				}
				best = max(best,count);
			}
		}
		return best;


		set<Eel> eels;
		for( int i = 0; i < l.size(); ++i )
		{
			eels.insert(Eel(i, t[i], t[i] + l[i]));
		}
		/*
		FOREACH(eel, eels )
		{
			cout<<eel->index<<": ";
			FOREACH(aeel,eels)
			{
				if( *eel == *aeel) continue;
				if( aeel->intersects(*eel))
				{
					cout<<aeel->index<<" ";
				}
			}
			cout<<endl;
		}
		cout<<"===="<<endl;
*/
		int ret = 1;

		vector<set<Eel> > cliques(l.size());
		FOREACH( eel, eels )
		{
			set<Eel> pKlik;
			pKlik.insert( *eel);
			d_print(eel->index);
			pKlik = findMaxClique( eels, pKlik );
			d_print(pKlik);
			if(pKlik.size() == l.size() ) return l.size();
			cliques[eel->index] = pKlik;
		}
		for( int i = 0; i < l.size(); ++i )
		{
			ret = max(ret,(int)cliques[i].size());
			for( int j = 0; j < l.size(); ++j )
			{
				int cnt = cliques[i].size();
				FOREACH(eel, cliques[j])
				{
					if( !IN(cliques[i], *eel))
						++cnt;
				}
				ret = max(ret,cnt);
			}
		}
		return ret;



	}
};
