#include "Headers.h"
#include "MainUpdate.h"





int main(void)
{
	// ** 최초에 생성 후 초기화
	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();
	
	while (true)
	{
		if (Time + 100 <= GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			Main.Update();
			Main.Render();			
		}
	}

	return 0;
}

