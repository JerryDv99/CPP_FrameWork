#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"

Bullet::Bullet()
{
	Time = 0;
}

Bullet::~Bullet()
{
}

void Bullet::Start()
{
	Key = "Bullet";

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	Speed = 0.5f;

	Target = nullptr;

	Time = GetTickCount64();

	//Info.Direction = MathManager::GetDirection(Info.Position, Target->GetPosition());
}

int Bullet::Update()
{	
	Info.Position += Info.Direction * Speed;

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
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*", 12);
}

void Bullet::Release()
{
}