#pragma once
#include "BulletBridge.h"

class FireBullet : public BulletBridge
{
public:
	virtual void Start()override;
	virtual int  Update(Transform& _Transform)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	FireBullet();
	virtual ~FireBullet();
};

