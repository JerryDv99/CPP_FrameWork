#include "Enemy.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "Bridge.h"
#include "Goolops.h"
#include "Mutant.h"
#include "Doomboo.h"

Enemy::Enemy() : pBridge(nullptr), Time(0)
{
}

Enemy::~Enemy()
{
	Release();
}

Object* Enemy::Start(string _Key)
{
	Key = "Enemy";

	Time = (GetTickCount64() - 7000);

	return this;
}

int Enemy::Update()
{
	if (pBridge)
	{
		pBridge->Update(Info);
		Time = GetTickCount64();
	}
	else
	{
		if (Time + 7000 < GetTickCount64())
		{
			Time = GetTickCount64();

			srand(int(Time * GetTickCount64()));
			switch (rand() % 3)
			{
			case 0:
				pBridge = new Goolops;
				break;
			case 1:
				pBridge = new Mutant;
				break;
			case 2:
				pBridge = new Doomboo;
				break;
			}
			pBridge->Start();
			pBridge->SetObject(this);
		}
	}
		
	/*
	if (Time + 7000 < GetTickCount64())
	{
		Vector3 PlayerPosition = ObjectManager::GetInstance()->GetPlayer()->GetPosition();

		if (Info.Position.x > PlayerPosition.x)
		{
			Object* pBullet = ObjectFactory<Bullet>::CreateObject(Info.Position);

			pBullet->SetDirection(MathManager::GetDirection(Info.Position, PlayerPosition));

			ObjectManager::GetInstance()->AddObject(pBullet);

			Time = GetTickCount64();
		}		
	}*/

	if ((Info.Position.x <= 0 || Info.Position.x >= 150 ||
		Info.Position.y <= 0 || Info.Position.y >= 40))
	{
		return 1;
	}

	Info.Position += Info.Direction * Speed;
	return 0;
}

void Enemy::Render()
{
	if (pBridge)
		pBridge->Render();
	//CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"Ȫ", 12);
}

void Enemy::Release()
{
	if (pBridge)
	{
		delete pBridge;
		pBridge = nullptr;
	}
	
}