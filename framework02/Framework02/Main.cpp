#include "MainUpdate.h"



int main(void)
{
	system("title ȫ�浿 : �����̸�");
	system("mode con cols = 160 lines = 50");

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