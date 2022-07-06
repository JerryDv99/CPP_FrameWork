#include "Headers.h"
#include "MainUpdate.h"





int main(void)
{
	Vector3 V1 = Vector3(1.0f, 1.0f);
	Vector3 V2 = Vector3(10.0f, 10.0f);

	Vector3 V3 = V1 - V2;
	Vector3 V4 = V1 + V2;

	cout << "V3.X : " << V3.x << endl;
	cout << "V3.X : " << V3.y << endl;

	cout << "V4.X : " << V4.x << endl;
	cout << "V4.X : " << V4.y << endl;

	/*MainUpdate Main;
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
	}*/

	return 0;
}

