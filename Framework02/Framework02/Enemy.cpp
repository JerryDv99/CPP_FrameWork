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

Bridge* Enemy::BridgeList[3];

Enemy::Enemy() : pBridge(nullptr), Time(0)
{
	for (int i = 0; i < 3; ++i)
		BridgeList[i] = nullptr;
}

Enemy::~Enemy()
{
	Release();
}

Object* Enemy::Start(string _Key)
{
	Key = _Key;

	Time = (GetTickCount64() - 7000);

	pBridge = nullptr;

	BridgeList[EnemyID_Goolops] = new Goolops;
	BridgeList[EnemyID_Mutant] = new Mutant;
	BridgeList[EnemyID_Doomboo] = new Doomboo;


	return this;
}

int Enemy::Update()
{
	Info.Position.x -= 1;

	if (pBridge)
		pBridge->Update(Info);
	else
	{
		if (Time + 7000 < GetTickCount64())
		{
			srand(int(Time * GetTickCount64()));
			switch (rand() % 3)
			{
			case EnemyID_Goolops:
				pBridge = BridgeList[EnemyID_Goolops]->Clone();
				break;

			case EnemyID_Mutant:
				pBridge = BridgeList[EnemyID_Mutant]->Clone();
				break;

			case EnemyID_Doomboo:
				pBridge = BridgeList[EnemyID_Doomboo]->Clone();
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
	}
	*/

	if ((Info.Position.x <= 0 || Info.Position.x >= 150 ||
		Info.Position.y <= 0 || Info.Position.y >= 40))
	{
		return 1;
	}

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