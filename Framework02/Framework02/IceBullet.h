#pragma once
#include "BulletBridge.h"

class IceBullet : public BulletBridge
{

public:
	virtual void Start()override;
	virtual int  Update(Transform& _Transform)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	IceBullet();
	virtual ~IceBullet();
};

