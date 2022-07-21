#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"

Logo::Logo()
{
	Time = 0;
	Count = 0;
}

Logo::~Logo()
{
}

void Logo::Start()
{
	Time = GetTickCount64();
}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RETURN)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render()
{
	for (int i = 0; i < 5; ++i)
	{
		if (Time + i * 1000 > GetTickCount64())
			CursorManager::GetInstance()->WriteBuffer(30.0f + 20.0f * i, 30.0f, (char*)"¡Ü", 14);
		if (Time + i * 1000 < GetTickCount64() && Time + i * 1000 + 500 > GetTickCount64())
		{
			CursorManager::GetInstance()->WriteBuffer(28.0f + 20.0f * Count, 30.0f, (char*)"¿Ê¤Ñ", 10);
			CursorManager::GetInstance()->WriteBuffer(70.0f, 32.0f, (char*)"Now Loading...");
		}
		if (Time + i * 1000 + 990 > GetTickCount64() && Time + i * 1000 + 500 < GetTickCount64())
		{
			CursorManager::GetInstance()->WriteBuffer(28.0f + 20.0f * Count, 30.0f, (char*)"¿Ê£¯", 10);		
			CursorManager::GetInstance()->WriteBuffer(70.0f, 32.0f, (char*)"Now Loading..");
		}
		if (Time + i * 1000 == GetTickCount64())
		{
			Count++;
			break;
		}
	}
	
	
	CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"Logo");
}

void Logo::Release()
{

}