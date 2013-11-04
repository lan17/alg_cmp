#include <string>

using namespace std;

class EllysNewNickname
{
	public:
		int getLength(string nickname)
		{
			string vowels = "aeiouy";
			int cnt = 0;
			bool pv = false;
			for( int i = 0; i < nickname.size(); ++i )
			{
				char c =  nickname[i];
				bool is_v = vowels.find(c) != string::npos;
				if( !is_v )
				{
					++cnt;
					pv = false;
				}
				else if( is_v && pv )
					continue;
				else
				{
					++cnt;
					pv = true;
				}
			}
			return cnt;
		}
};
