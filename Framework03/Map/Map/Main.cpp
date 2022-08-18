#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

using namespace std;

namespace std
{
	template<typename T1, typename T2>
	class map
	{
	public:
		T1 Key;
		T2 Value;		
	};
}
int main(void)
{
	{
		map<string, int> Number;

		//Number.Key = "È«±æµ¿";
		//Number.Value = 32;

		// µ¥ÀÌÅÍ »ğÀÔ 1
		Number.insert(make_pair("È«±æµ¿", 32));
		Number.insert(make_pair("ÀÓ²©Á¤", 35));

		// µ¥ÀÌÅÍ »ğÀÔ 2
		Number["ÀÌ¸ù·æ"] = 38;

		// ÀÌÁøÆ®¸®

		map<string, int>::iterator iter = Number.find("ÀÌ¸ù·æ");

		cout << iter->second << endl;
	}

	{
		{
			map<string, list<int>> Number;
		}
	
		{
			map<string, vector<int>> Number;
		}
	
		{
			vector<map<int, string>> Number;

			for (int i = 0; i < 10; ++i)
			{
				Number.push_back
				Number[0].insert(make_pair(32, "È«±æµ¿"));
				
				map<int, string>::iterator iter = Number[i].find(i);

				iter->second
			}
		}
	}


	return 0;
}