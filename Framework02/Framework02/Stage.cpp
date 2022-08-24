#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "ObjectFactory.h"


Stage::Stage() : EnemyTime(0), BulletTime(0)
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Start()
{
	ObjectManager::GetInstance()->SetPlayer(ObjectFactory<Player>::CreateObject(150.f / 2, 40.f / 2));

	EnemyTime = GetTickCount64();
}

void Stage::Update()
{
	// 100 : 100 = player.x : x

	Vector3 PlayerPosition = ObjectManager::GetInstance()->GetPlayer()->GetPosition();
	float Result = ((PlayerPosition.x * 100) / 100);

	Result = (100 - Result);

	Result = Result / 100;	

	if (EnemyTime + (2500 * Result) < GetTickCount64())
	{
		Object* pEnemy = ObjectFactory<Enemy>::CreateObject(rand() % 130 + 1, rand() % 39 + 1);

		ObjectManager::GetInstance()->AddObject(pEnemy);

		EnemyTime = GetTickCount64();
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		if (BulletTime + 200 < GetTickCount64())
		{
			Object* pBullet = ObjectFactory<Bullet>::CreateObject(rand() % 10 + 1, rand() % 39 + 1);

			pBullet->SetDirection(Vector3(1.0, 0.0));

			ObjectManager::GetInstance()->AddObject(pBullet);

			BulletTime = GetTickCount64();
		}
	}

	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	
}
