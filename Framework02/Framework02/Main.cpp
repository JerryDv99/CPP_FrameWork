#include "Headers.h"
#include "MainUpdate.h"
#include "Singleton.h"



Singleton* Singleton::Instance = nullptr;	// private�� Instance�� ��Ÿ�� ���� �ʱ�ȭ���� �� Instance�� ���� �����Ǿ� �������� ���ٰ���


int main(void)
{
	// ** ���ʿ� ���� �� �ʱ�ȭ
	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();
	
	while (true)
	{
		if (Time + 1000 <= GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			// ** ������� �� �浹 ���� �̺�Ʈ üũ
			Main.Update();

			// ** �׸���
			Main.Render();			
		}
	}

	return 0;
}

// ** DWORD unsigned long
// ** ULONGLONG unsigned __int64 
// DWORD dwTime = GetTickCount();
//				1 / 1000��	max 49��
//				1 / 1000��	max 500��
