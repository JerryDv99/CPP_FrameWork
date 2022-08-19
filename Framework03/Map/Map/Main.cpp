#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <vector>
#include <list>

using namespace std;

/*
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
*/


int main(void)
{
	/*
	{
		map<string, int> Number;

		//Number.Key = "È«±æµ¿";
		//Number.Value = 32;

		// µ¥ÀÌÅÍ »ğÀÔ 1
		Number.insert(make_pair("È«±æµ¿", 32));
		Number.insert(make_pair("ÀÓ²©Á¤", 35));

		// µ¥ÀÌÅÍ »ğÀÔ 2
		Number["ÀÌ¸ù·æ"] = 38;

		// find
		map<string, int>::iterator iter = Number.find("ÀÌ¸ù·æ");
		cout << iter->second << endl;
	}
	*/

	{
		{
			//map<string, list<int>> Number;
		}
	
		{
			//map<string, vector<int>> Number;
		}
		
		/*
		{
			vector<map<int, string>> Number;

			for (int i = 0; i < 10; ++i)
			{
				map<int, string> Temp;
				Temp.insert(make_pair(i, "È«±æµ¿ÀÓ²©Á¤"));
				Number.push_back(Temp);

				map<int, string>::iterator iter = Number[i].find(i);

				if (!Number.empty())
					cout << iter->second.find("Á¤") << endl;
			}
		}
		*/

		// µ¥ÀÌÅÍ Ã£±â
		/*
		{
			class Object
			{
			private:
				string Key;
				int Attack;
			public:
				void Initialize() {	Key = "";	Attack = rand() ;	}
				void Render() {	cout << Key << "°ø°İ·Â : " << Attack << endl; }
			public:
				string GetKey() { return Key; }
				void SetKey(const string& _Key) { Key = _Key; }
				void SetAttack(const int& _Attack) { Attack = _Attack; }
			public:
				Object* Front;
				Object* Back;

			};




			{
				// map »ı¼º
				map<string, list<Object*>> ObjectList;

				for (int i = 0; i < 5; ++i)
				{
					Object* pObj = new Object;
					pObj->Initialize();

					string str = "";
					cout << "ÀÌ¸§ ÀÔ·Â : "; cin >> str;
					pObj->SetKey(str);

					map<string, list<Object*>>::iterator iter = ObjectList.find(pObj->GetKey());

					if (iter == ObjectList.end())
					{
						list<Object*> TempList;
						TempList.push_back(pObj);

						// map µ¥ÀÌÅÍ »ğÀÔ
						ObjectList.insert(make_pair(pObj->GetKey(), TempList));
					}
					else
					{
						iter->second.push_back(pObj);
					}
				}

				cout << "** ÀÔ·Â Á¾·á **" << endl << endl;

				cout << "** Å½»ö ½ÃÀÛ**" << endl;

				while(true)
				{
					string str = "";
					cout << "ÀÌ¸§ ÀÔ·Â : "; cin >> str;

					// map ¿¡¼­ ÀÚ·á Å½»ö
					map<string, list<Object*>>::iterator iter = ObjectList.find(str);
					// map<first, second>
					if (iter == ObjectList.end())
					{
						cout << "¹«±â°¡ ¾ø½À´Ï´Ù." << endl;
						continue;
					}
					else
					{
						for (list<Object*>::iterator iter2 = iter->second.begin();
							iter2 != iter->second.end(); ++iter2)
						{
							(*iter2)->Render();
						}
					}
				}
			}
		}
		*/



		int i = 0;

		/*
		{
			multimap<string, int> strList;
			
			strList.insert(make_pair("È«±æµ¿", 1));
			strList.insert(make_pair("È«±æµ¿", 2));
			strList.insert(make_pair("È«±æµ¿", 3));
			strList.insert(make_pair("È«±æµ¿", 4));
			strList.insert(make_pair("È«±æµ¿", 5));
			strList.insert(make_pair("È«±æµ¿", 6));
			strList.insert(make_pair("È«±æµ¿", 7));
			strList.insert(make_pair("È«±æµ¿", 8));
			strList.insert(make_pair("È«±æµ¿", 9));
			strList.insert(make_pair("È«±æµ¿", 10));

			for (multimap<string, int>::iterator iter = strList.begin();
				iter != strList.end(); ++iter)
			{
				cout << iter->first << " : " << iter->second << endl;
			}
		}
		*/


		{
			class Vector3
			{
			public:
				float x, y, z;
				Vector3() : x(0), y(0), z(0) {}
				Vector3(float _x, float _y) : x(_x), y(_y), z(0) {}
				Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
			};

			class Object
			{
			private:
				string Key;
				Vector3 Position;

				Object* Target;
			public:
				void Initialize()
				{
					Key = "";

					srand(GetTickCount64());

					Position = Vector3(
						rand() % 50 + 1,
						rand() % 50 + 1);
				}
				void Render() {
					cout << "X : " << Position.x << endl;
					cout << "Y : " << Position.y << endl; }
			public:
				string GetKey() const { return Key; }
				Vector3 GetPosition() const { return Position; }
				void SetKey(const string& _Key) { Key = _Key; }
				void SetTarget(const Object* _Target) { Target = Target; }
				void SetPosition(const float& _x, const float _y) { Position = Vector3(_x, _y); }
			};

			Object* Player = new Object;
			Player->SetPosition(25.0f, 25.0f);
			multimap<float, Object*> ObjectList;

			for (int i = 0; i < 5; ++i)
			{
				Object* pObj = new Object;
				pObj->Initialize();

				pObj->SetTarget(Player);

				pObj->SetKey("Enemy");

				Vector3 EnemyPosition; 
				Vector3 PlayerPosition;

				float X = pObj->GetPosition().x - Player->GetPosition().x;
				float Y = pObj->GetPosition().y - Player->GetPosition().y;

				float D = sqrt((X * X) + (Y * Y));

				ObjectList.insert(make_pair(3.0f, pObj));
			}

			for (multimap<float, Object*>::iterator iter = ObjectList.begin();
				iter != ObjectList.end(); ++iter)
			{
				cout << iter->first << endl;
				iter->second->Render();
			}

			multimap<float, Object*>::iterator iter = ObjectList.begin();
			Player->SetTarget((*iter).second);
		}
	}


	return 0;
}