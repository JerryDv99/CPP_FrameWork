#include "MainUpdate.h"
#include "SceneManager.h"


MainUpdate::MainUpdate() : Count(0)
{

}
MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Start()
{
	SceneManager::GetInstance()->SetScene(SCENEID::LOGO);
}

void MainUpdate::Update()
{
	
}

void MainUpdate::Render()
{
	
}

void MainUpdate::Release()
{
	
}
