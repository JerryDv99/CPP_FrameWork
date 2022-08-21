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

		//Number.Key = "ȫ�浿";
		//Number.Value = 32;

		// ������ ���� 1
		Number.insert(make_pair("ȫ�浿", 32));
		Number.insert(make_pair("�Ӳ���", 35));

		// ������ ���� 2
		Number["�̸���"] = 38;

		// find
		map<string, int>::iterator iter = Number.find("�̸���");
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
				Temp.insert(make_pair(i, "ȫ�浿�Ӳ���"));
				Number.push_back(Temp);

				map<int, string>::iterator iter = Number[i].find(i);

				if (!Number.empty())
					cout << iter->second.find("��") << endl;
			}
		}
		*/

		// ������ ã��
		/*
		{
			class Object
			{
			private:
				string Key;
				int Attack;
			public:
				void Initialize() {	Key = "";	Attack = rand() ;	}
				void Render() {	cout << Key << "���ݷ� : " << Attack << endl; }
			public:
				string GetKey() { return Key; }
				void SetKey(const string& _Key) { Key = _Key; }
				void SetAttack(const int& _Attack) { Attack = _Attack; }
			public:
				Object* Front;
				Object* Back;

			};




			{
				// map ����
				map<string, list<Object*>> ObjectList;

				for (int i = 0; i < 5; ++i)
				{
					Object* pObj = new Object;
					pObj->Initialize();

					string str = "";
					cout << "�̸� �Է� : "; cin >> str;
					pObj->SetKey(str);

					map<string, list<Object*>>::iterator iter = ObjectList.find(pObj->GetKey());

					if (iter == ObjectList.end())
					{
						list<Object*> TempList;
						TempList.push_back(pObj);

						// map ������ ����
						ObjectList.insert(make_pair(pObj->GetKey(), TempList));
					}
					else
					{
						iter->second.push_back(pObj);
					}
				}

				cout << "** �Է� ���� **" << endl << endl;

				cout << "** Ž�� ����**" << endl;

				while(true)
				{
					string str = "";
					cout << "�̸� �Է� : "; cin >> str;

					// map ���� �ڷ� Ž��
					map<string, list<Object*>>::iterator iter = ObjectList.find(str);
					// map<first, second>
					if (iter == ObjectList.end())
					{
						cout << "���Ⱑ �����ϴ�." << endl;
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
			
			strList.insert(make_pair("ȫ�浿", 1));
			strList.insert(make_pair("ȫ�浿", 2));
			strList.insert(make_pair("ȫ�浿", 3));
			strList.insert(make_pair("ȫ�浿", 4));
			strList.insert(make_pair("ȫ�浿", 5));
			strList.insert(make_pair("ȫ�浿", 6));
			strList.insert(make_pair("ȫ�浿", 7));
			strList.insert(make_pair("ȫ�浿", 8));
			strList.insert(make_pair("ȫ�浿", 9));
			strList.insert(make_pair("ȫ�浿", 10));

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