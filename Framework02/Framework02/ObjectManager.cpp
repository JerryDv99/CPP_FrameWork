#include "ObjectManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "CursorManager.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr), pEnemy(nullptr)
{
	for (int i = 0; i < 128; ++i)
		pBullet[i] = nullptr;
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::CreateObject(int _StateIndex, float _Power)
{
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i] == nullptr)
		{
			pBullet[i] = new Bullet;
			pBullet[i]->Start();
			

			switch (_StateIndex)
			{
			case 0:
			{
				pBullet[i]->SetPosition(74.0f, 1.0f);
				Vector3 Direction = pPlayer->GetPosition() - pBullet[i]->GetPosition();
				pBullet[i]->SetDirection(Direction);
				((Bullet*)pBullet[i])->SetIndex(_StateIndex);
				((Bullet*)pBullet[i])->SetTime(GetTickCount64());
			}
				break;
			case 1:
				pBullet[i]->SetPosition(74.0f, 1.0f);
				pBullet[i]->SetTarget(pPlayer);
				((Bullet*)pBullet[i])->SetIndex(_StateIndex);
				((Bullet*)pBullet[i])->SetTime(GetTickCount64());
				break;
			case 2:
			{
				if (_Power != 0)
				{
					pBullet[i]->SetPosition(pPlayer->GetPosition());
					Vector3 Direction = pEnemy->GetPosition() - pPlayer->GetPosition();
					pBullet[i]->SetDirection(Direction);
					((Bullet*)pBullet[i])->SetIndex(_StateIndex);
					((Bullet*)pBullet[i])->SetPower(pPlayer->GetPower());
					break;
				}
			}
			}
			break;
		}
	}
}

void ObjectManager::Start()
{
	pPlayer = new Player;
	pPlayer->Start();
	
	pEnemy = new Enemy;
	pEnemy->Start();
}

void ObjectManager::Update()
{
	pPlayer->Update();
	

	int result = 0;

	if (pEnemy)
	{
		pEnemy->Update();
		if (CollisionManager::RectCollision(
			pPlayer->GetTransform(),
			pEnemy->GetTransform()))
		{
			delete pEnemy;
			pEnemy = nullptr;
		}
	}
	

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
		{
			result = pBullet[i]->Update();

			if (CollisionManager::RectCollision(
				pPlayer->GetTransform(),
				pBullet[i]->GetTransform()) && !((Bullet*)pBullet[i])->GetIndex() == 2)
			{
				CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"충돌입니다");
				result = 1;
			}
			
			if (pEnemy)
			{
				if (CollisionManager::RectCollision(
					pEnemy->GetTransform(),
					pBullet[i]->GetTransform()) && ((Bullet*)pBullet[i])->GetIndex() == 2)
				{
					CursorManager::GetInstance()->WriteBuffer(0.0f, 1.0f, (char*)"Enemy 충돌", 12);
					result = 1;
				}
			}			
		}

		if (result == 1)
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}
}

void ObjectManager::Render()
{
	pPlayer->Render();

	if(pEnemy)
		pEnemy->Render();

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
			pBullet[i]->Render();
	}
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	delete pEnemy;
	pEnemy = nullptr;
	
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}
}