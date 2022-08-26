#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "ObjectFactory.h"


Stage::Stage() : Time(0)
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Start()
{
	ObjectManager::GetInstance()->SetPlayer(ObjectFactory<Player>::CreateObject(150.f / 2, 40.f / 2));

	Time = GetTickCount64();
}

void Stage::Update()
{
	srand(pow(GetTickCount64(), 2));

	if (GetAsyncKeyState(VK_TAB))
	{
		if (Time + 250 < GetTickCount64())
		{
			Object* pBullet = ObjectFactory<Bullet>::CreateObject();

			((Bullet*)pBullet)->SetIndex(1);
			pBullet->SetTarget(
				ObjectManager::GetInstance()->GetPlayer());

			ObjectManager::GetInstance()->AddObject(pBullet);

			Time = GetTickCount64();
		}
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		if (Time + 500 < GetTickCount64())
		{
			Object* pEnemy = ObjectFactory<Enemy>::CreateObject();
			((Enemy*)pEnemy)->SetPosition(rand() % 150, rand() % 40);

			pEnemy->SetTarget(ObjectManager::GetInstance()->GetPlayer());

			ObjectManager::GetInstance()->AddObject(pEnemy);

			Time = GetTickCount64();
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
