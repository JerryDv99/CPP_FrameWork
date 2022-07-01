#include "Logo.h"
#include "SceneManager.h"

Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Start()
{

}

void Logo::Update()
{
	SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render()
{

}

void Logo::Release()
{

}