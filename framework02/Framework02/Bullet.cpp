#include "Bullet.h"
#include "FireBullet.h"
#include "IceBullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"

Bullet::Bullet() : pBridge(nullptr)
{
	Time = 0;
}

Bullet::~Bullet()
{
	Release();
}

Object* Bullet::Start(string _Key)
{
	Key = "Bullet";

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	Speed = 0.5f;

	Target = nullptr;

	Time = GetTickCount64();


	return this;
}

int Bullet::Update()
{	
	Info.Position += Info.Direction * Speed;

	if (pBridge)
	{
		pBridge->Update(Info);
		Time = GetTickCount64();
	}
	else
	{
		if (Time + 200 < GetTickCount64() && GetAsyncKeyState(VK_SPACE))
		{
			Time = GetTickCount64();

			srand(int(Time * GetTickCount64()));
			switch (rand() % 2)
			{
			case 0:
				pBridge = new FireBullet;
				break;
			case 1:
				pBridge = new IceBullet;
				break;
			}
			pBridge->Start();
			pBridge->SetObject(this);
		}
	}

	if (Time + 2500 < GetTickCount64())
		return 2;

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