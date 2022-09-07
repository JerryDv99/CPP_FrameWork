#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "InputManager.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "ObjectFactory.h"
#include "PrototypeManager.h"
#include "ScrollBox.h"
#include "Skill.h"

Stage::Stage() : EnemyTime(0)
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Start()
{
	Object* pObj = PrototypeManager::GetInstance()->FindObject("Player")->Clone();

	if (pObj != nullptr)
		ObjectManager::GetInstance()->SetPlayer(pObj);

	EnemyTime = GetTickCount64();

	const int Max = 5;

	char* Texture[5][5] = {

	};


	for (int i = 0; i < Max; ++i)
	{
		Object* pSkill = new Skill;
		pSkill->SetPosition(int(14 * i  + (150 - (14 * Max ))), 
			int(39 - (7 * 0.5f)));
		pSkill->Start("Skill");

		pSkillList.push_back(pSkill);
	}

	for (int i = 0; i < 20; ++i)
		ObjectManager::GetInstance()->AddObject(Vector3(rand() % 150, rand() % 40), "Enemy");	
}

void Stage::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	



	UserInterface* Box = new ScrollBox;
	Box->Start();

	/*if (GetAsyncKeyState(VK_SPACE))
	{
		ObjectManager::GetInstance()->AddObject(ObjectManager::GetInstance()->GetPlayer()->GetPosition(), "Bullet");
	}*/
	/*
	Vector3 PlayerPosition = ObjectManager::GetInstance()->GetPlayer()->GetPosition();
	float Result = ((PlayerPosition.x * 100) / 100);
	Result = (100 - Result);
	Result = Result / 100;

	if (EnemyTime + (2500 * Result) < GetTickCount64())
	{
		srand(int(GetTickCount64() * EnemyTime));

		Object* pEnemy = PrototypeManager::GetInstance()->FindObject("Enemy")->Clone();

		if (pEnemy != nullptr)
		{
			pEnemy->SetPosition(
				float(rand() % 148 + 1),
				float(rand() % 39 + 1));

			ObjectManager::GetInstance()->AddObject(pEnemy);
		}

		EnemyTime = GetTickCount64();
	}*/

	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();

	for (vector<Object*>::iterator iter = pSkillList.begin(); iter != pSkillList.end(); ++iter)
	{
		(*iter)->Render();

	}
}

void Stage::Release()
{
	
}
