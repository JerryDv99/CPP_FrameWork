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
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Bullet(*this); }
public:
	void SetTime(ULONGLONG _Time) { Time = _Time; }
public:
	Bullet();
	Bullet(Transform _Info) : Object(_Info) {};
	virtual ~Bullet();
};

