#pragma once
#include "Object.h"

class Bridge;
class Bullet : public Object
{
private:
	Bridge* pBridge;
	ULONGLONG Time;
public:
	void SetBridge(Bridge* _Bridge) { pBridge = _Bridge; }
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

