#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	int Index;
	ULONGLONG Time;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetIndex(int _Index) { Index = _Index; }
	void SetTime(ULONGLONG _Time) { Time = _Time; }
public:
	Bullet();
	virtual ~Bullet();
};

