#include "IceBullet.h"
#include "Bullet.h"
#include "CursorManager.h"

IceBullet::IceBullet()
{
}

IceBullet::~IceBullet()
{
}

void IceBullet::Start()
{
}

int IceBullet::Update(Transform& _Transform)
{
	return 0;
}

void IceBullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(pObject->GetPosition(), (char*)"¢º", 9);
}

void IceBullet::Release()
{
}
