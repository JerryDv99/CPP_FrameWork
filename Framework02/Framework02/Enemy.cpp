#include "Enemy.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"

Enemy::Enemy() : Time(0), Count(0)
{
}

Enemy::~Enemy()
{
}

void Enemy::Start()
{
	Key = "Enemy";

	Info.Position = Vector3(74.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);
	Info.Direction = Vector3(-1.0f, 0.0f);

	Target = nullptr;
	Count = 0;
	Speed = 0.2f;
	Time = (GetTickCount64() - 7000);
}

int Enemy::Update()
{
	if (Time + 7000 < GetTickCount64())
	{
		Vector3 PlayerPosition = ObjectManager::GetInstance()->GetPlayer()->GetPosition();

		if (Info.Position.x > PlayerPosition.x)
		{
			Object* pBullet = ObjectFactory<Bullet>::CreateObject(Info.Position);

			pBullet->SetTarget(ObjectManager::GetInstance()->GetPlayer());

			pBullet->SetDirection(MathManager::GetDirection(Info.Position, PlayerPosition));

			ObjectManager::GetInstance()->AddObject(pBullet);

			Time = GetTickCount64();
		}		
	}

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
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"Ȫ", 12);
}

void Enemy::Release()
{

}