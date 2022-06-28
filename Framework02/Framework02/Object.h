#pragma once
#include "Headers.h";

class Object
{
private:
	int Time;
	int Minute;
	int Second;
public:
	void Start();
	void Update();
	void Render();
	void Release();
public:
	Object();
	~Object();
};

