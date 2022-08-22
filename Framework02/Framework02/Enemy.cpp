#include "Enemy.h"
#include "ObjectManager.h"
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

	Target = nullptr;
	Count = 0;
	Time = GetTickCount64();
}

int Enemy::Update()
{
	Info.Direction = MathManager::GetDirection(Info.Position, Target->GetPosition());
	Info.Position += Info.Direction * (0.05f);
	return 0;
}

void Enemy::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"Ȫ", 12);
}

void Enemy::Release()
{

}