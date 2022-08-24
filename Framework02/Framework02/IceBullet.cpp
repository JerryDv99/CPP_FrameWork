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
	Check = false;
}

int IceBullet::Update(Transform& _Transform)
{
	if (_Transform.Position.y <= 1)
		Check = false;
	else if (_Transform.Position.y == 39)
		Check = true;

	if (!Check)
		_Transform.Position.y += 0.5;
	if (Check)
		_Transform.Position.y -= 0.5;
	return 0;
}

void IceBullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(pObject->GetPosition(), (char*)"¢º", 9);
}

void IceBullet::Release()
{
}
