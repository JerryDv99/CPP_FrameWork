#include "ObjectpoolManager.h"
#include "PrototypeManager.h"
#include "Object.h"

ObjectpoolManager* ObjectpoolManager::Instance = nullptr;

ObjectpoolManager::ObjectpoolManager()
{
}

ObjectpoolManager::~ObjectpoolManager()
{
}

void ObjectpoolManager::GetObject(string _Key)
{
	auto iter = DisableList.find(_Key);

	if (iter == DisableList.end())
	{
		list<Object*> Temp;
		Temp.push_back(PrototypeManager::GetInstance()->FindObject(_Key)->Clone());
		EnableList.insert(make_pair(_Key, Temp));
	}
	else
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end();)
		{
			if ((*iter2)->GetKey() == _Key)
			{
				list<Object*> Temp;
				Temp.push_back((*iter2));
				EnableList.insert(make_pair(_Key, Temp));
				break;
			}
			else
				++iter2;
		}
	}	
}

void ObjectpoolManager::SwitchingObject(Object* _Object)
{
	auto iter = DisableList.find(_Object->GetKey());

	if (iter == DisableList.end())
	{
		list<Object*> Temp;
		Temp.push_back(_Object);
		DisableList.insert(make_pair(_Object->GetKey(), Temp));
	}
	else
		iter->second.push_back(_Object);
}

void ObjectpoolManager::Update()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end();)
		{
			int Result = (*iter2)->Update();

			if (Result)
			{
				SwitchingObject((*iter2));
				iter2 = iter->second.erase(iter2);
			}
			else
				++iter2;
		}
	}
}

void ObjectpoolManager::Render()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}
}
