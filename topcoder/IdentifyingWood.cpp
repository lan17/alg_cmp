#include <string>

using namespace std;


class IdentifyingWood
{
	public:
		string check(string s, string t)
		{
			int k = 0;
			int i = -1;
			while (true)
			{
				if (k == t.size())
				{
					break;
				}
				i = s.find(t[k++], i+1);
				if (i == string::npos)
				{
					return "Nope.";
				}
			}
			return "Yep, it's wood.";
		}
};
