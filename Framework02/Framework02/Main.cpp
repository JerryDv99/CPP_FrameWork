#include "Headers.h"
#include "MainUpdate.h"
#include "Singleton.h"



Singleton* Singleton::Instance = nullptr;	// private인 Instance를 런타임 이전 초기화시켜 새 Instance가 힙에 생성되어 전역에서 접근가능


int main(void)
{
	// ** 최초에 생성 후 초기화
	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();
	
	while (true)
	{
		if (Time + 1000 <= GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			// ** 변경사항 및 충돌 등의 이벤트 체크
			Main.Update();

			// ** 그리기
			Main.Render();			
		}
	}

	return 0;
}

// ** DWORD unsigned long
// ** ULONGLONG unsigned __int64 
// DWORD dwTime = GetTickCount();
//				1 / 1000초	max 49일
//				1 / 1000초	max 500년
