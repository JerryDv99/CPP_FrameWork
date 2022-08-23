#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	ULONGLONG Time;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetTime(ULONGLONG _Time) { Time = _Time; }
public:
	Bullet();
	virtual ~Bullet();
};

