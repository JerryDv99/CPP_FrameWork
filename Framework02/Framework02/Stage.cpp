#include "Stage.h"
#include "SceneManager.h"
#include "Player.h"
#include "Enemy.h"

Stage::Stage()
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Start()
{
	pPlayer = new Player;
	pPlayer->Start();

	pEnemy = new Enemy;
	pEnemy->Start();
}

void Stage::Update()
{
	pPlayer->Update();
	pEnemy->Update();
}

void Stage::Render()
{
	pPlayer->Render();
	pEnemy->Render();
}

void Stage::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
	
	delete pEnemy;
	pEnemy = nullptr;
}
