#include <iostream>
#include <Windows.h>

using namespace std;




int main(void)
{
	// ** DWORD unsigned long
	// ** ULONGLONG unsigned __int64

	//				1 / 1000��	max 49��
	DWORD dwTime = GetTickCount();

	//				1 / 1000��	max 500��
	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time < GetTickCount64())
		{
			Time = GetTickCount64();
		}
	}

	return 0;
}