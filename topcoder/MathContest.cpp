#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>

using namespace std;

class MathContest 
{
	public:
	int countBlack(string ballSequence, int repetitions) 
	{
		bitset<3500*50> seq;
		string seqs = ballSequence;
		for( int i = 0; i < repetitions-1; ++i )
		{
			seqs += ballSequence;
		}
		if( seqs.size() == 1 && seqs[0] == 'B' ) return 1;
		else if( seqs.size() == 1 ) return 0;
		
		int n = seqs.size(); 
		
		for( int i = 0; i  < n; ++i )
		{
			seq[i] = seqs[i] == 'W' ? false: true;
		}
		
		int front_pos = 0;
		int end_pos = n-1;
		
		bool front = true;
		
		int ans = 0;
		
		while( front_pos <= end_pos )
		{
			int pos = front ? front_pos:end_pos;
			bool black = seq[pos];
			if( front ) front_pos++;
			else end_pos--;
			
			if( black )
			{
				ans++;
				seq.flip();
			}
			if( ! black )
			{
				front = !front;
			}
		}
		
		return ans;
		
		
		/*
		
		
		
		while( seq.size() > 0 )
		{
			char top = seq[0];
			seq = seq.substr(1);
			if( top == 'W' )
			{
				reverse(seq.begin(),seq.end() );
			}
			if( top == 'B' )
			{
				ans++;
				for( int i = 0; i < seq.size(); ++i )
				{
					seq[i] = seq[i] == 'W' ? 'B':'W';
				}
			}
		}
		return ans;//*repetitions;
		*/
	}
};
