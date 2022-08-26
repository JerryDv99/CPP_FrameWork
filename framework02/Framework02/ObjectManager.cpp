#include "ObjectManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"
#include "ObjectpoolManager.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr)
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::AddObject(Object* _Object)
{
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object->GetKey());

	if (iter == ObjectList.end())
	{
		list<Object*> Temp;

		Temp.push_back(_Object);

		ObjectList.insert(make_pair(_Object->GetKey(), Temp));
	}
	else
		iter->second.push_back(_Object);
}

void ObjectManager::Update()
{
	pPlayer->Update();

	ObjectpoolManager::GetInstance()->Update();
}

void ObjectManager::Render()
{
	pPlayer->Render();

	ObjectpoolManager::GetInstance()->Render();
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	for (auto iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			delete (*iter2);
			(*iter2) = nullptr;
		}
		iter->second.clear();
	}
	ObjectList.clear();
}