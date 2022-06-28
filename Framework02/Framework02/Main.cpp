#include "Headers.h"

// ** Singleton ('����, ������' ��ü)
// static : ���� ����, ���� �ּұ� ������ �ϳ��� ����, ������ ����
// ������ ������ ������ �ö󰡴� ���� RValue(���)����
// ���� ������ ����, static�̾ ���� ������ ���ÿ� ����
class Singleton
{
private:	// ������ ������ �ݴ� �ƴ�
	static Singleton* Instance;	// (= new Singleton) static�� ������ ������ Instatnce�� , ���� Singleton* ���� �Ҵ��ϰ� static�� ����Ŵ
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Singleton;
		return Instance;
	}

	int Number;
};

Singleton* Singleton::Instance = nullptr;



int main(void)
{
	static Singleton* Instance = new Singleton;

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
