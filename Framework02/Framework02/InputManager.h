#pragma once
#include "Headers.h"

class InputManager
{
private:
	static InputManager* Instance;	
public:
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new InputManager;
		return Instance;
	}
private:
	DWORD dwKey;
	float Power;
	bool Check;
public:
	void CheckKey();
	bool GetCheck() { return Check; }
	int GetPower() { return Power; }
	DWORD GetKey() { return dwKey; }
private:
	InputManager();
public:
	~InputManager();
};