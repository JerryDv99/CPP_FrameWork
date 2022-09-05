#include "FireBullet.h"
#include "Bullet.h"
#include "CursorManager.h"

FireBullet::FireBullet()
{
}

FireBullet::~FireBullet()
{
}

void FireBullet::Start()
{
}

int FireBullet::Update(Transform& _Transform)
{
	
	return 0;
}

void FireBullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(pObject->GetPosition(), (char*)"¢º", 12);
}

void FireBullet::Release()
{
}
