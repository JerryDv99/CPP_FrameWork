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
	virtual Bridge* Clone()override { return new FireBullet(*this); }
public:
	FireBullet();
	virtual ~FireBullet();
};

