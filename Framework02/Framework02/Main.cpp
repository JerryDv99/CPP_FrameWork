#include "MainUpdate.h"



int main(void)
{
	system("title 홍길동 : 게임이름");
	system("mode con cols = 150 lines = 40");

	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();
	
	while (true)
	{
		if (Time <= GetTickCount64())
		{
			system("cls");

			Main.Update();
			Main.Render();
		}
	}

	return 0;
}
