#include "Bullet.h"
#include "FireBullet.h"
#include "IceBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"

Bridge* Bullet::BridgeList[2];

Bullet::Bullet() : pBridge(nullptr)
{
	for (int i = 0; i < 2; ++i)
		BridgeList[i] = nullptr;
	Time = 0;
}

Bullet::~Bullet()
{
	Release();
}

Object* Bullet::Start(string _Key)
{
	Key = _Key;

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	Speed = 1.0f;

	BridgeList[BulletID_Fire] = new FireBullet;
	BridgeList[BulletID_Ice] = new IceBullet;

	Time = GetTickCount64();

	return this;
}

int Bullet::Update()
{	
	Info.Position.x += 1;

	
	if (pBridge)
		pBridge->Update(Info);
	else
	{
		if (Time + 2000 < GetTickCount64())
		{
			srand(int(Time * GetTickCount64()));
			switch (rand() % 2)
			{
			case BulletID_Fire:
				pBridge = BridgeList[BulletID_Fire]->Clone();
				break;
			case BulletID_Ice:
				pBridge = BridgeList[BulletID_Ice]->Clone();
				break;
			}
			pBridge->Start();
			pBridge->SetObject(this);
		}
	}


	if ((Info.Position.x <= 0 || Info.Position.x >= 150 ||
		Info.Position.y <= 0 || Info.Position.y >= 40))
	{
		return 1;
	}
	return 0;
}

void Bullet::Render()
{
	
	if (pBridge)
		pBridge->Render();
	
	//CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*", 12);
}

void Bullet::Release()
{
	
	if (pBridge)
	{
		delete pBridge;
		pBridge = nullptr;
	}
	
}