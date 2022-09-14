#include "MainUpdate.h"



int main(void)
{
	system("title È«±æµ¿ : °ÔÀÓÀÌ¸§");
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
/*
	cout << "   __*_" << endl;
	cout << "¦£\"LSPD`¦¡¦¤" << endl;
	cout << "¦¦£ï¦¡¦¡£ï¦¥" << endl;

	cout << "¦£¦¡¦¡¦¡¦¡**¦¤" << endl;
	cout << "¦¢       ¦¢ ¦¢___" << endl;
	cout << "¦¢ LSPD         ¦¢" << endl;
	cout << "¦¦¦¡£ï¦¡¦¡¦¡¦¡£ï¦¥" << endl;

	cout << "¡Û  ¡Û" << endl;
	cout << "  ¡á" << endl;
	cout << "¡Û  ¡Û" << endl;

	cout << "¡Ý  ¡Ý" << endl;
	cout << "  ¡á" << endl;
	cout << "¡Ý  ¡Ý" << endl;

	cout << "¡Ü  ¡Ü" << endl;
	cout << "  ¡á" << endl;
	cout << "¡Ü  ¡Ü" << endl;






	cout << "   ____" << endl;
	cout << "¦£¢©   `¦¡¦¤" << endl;
	cout << "¦¦£ï¦¡¦¡£ï¦¥" << endl;

	cout << "     ____" << endl;
	cout << "¦£¦¡¢©   `¦¤" << endl;
	cout << "¦¦£ï¦¡¦¡£ï¦¥" << endl;

	cout << " ___________" << endl;
	cout << "¦¢         ]¡¬_" << endl;
	cout << "¦¢            ¦¢" << endl;
	cout << "¦¦¦¡£ï¦¡¦¡¦¡£ï¦¥" << endl;
	
	cout << "   ____________" << endl;
	cout << " _/ [         ¦¢" << endl;
	cout << "¦¢            ¦¢" << endl;
	cout << "¦¦£ï¦¡¦¡¦¡£ï¦¡¦¥" << endl;






	cout << "    _____" << endl;
	cout << "¦£-¢©  ¿À`¦¡¦¤" << endl;
	cout << "¦¦-£ï¦¡¦¡-£ï¦¥" << endl;

	cout << "        ____" << endl;
	cout << "¦¡¦¨ ¿Ê¤Ó  ]¡¬_" << endl;
	cout << "¦£¦ª-¦ª¦¥     ¦¢" << endl;
	cout << "¦¦¦¡£ï¦¡¦¡¦¡£ï¦¥" << endl;

	cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤¤Ó____" << endl;
	cout << "¦¢                      ¦£¦¡¦¨¦¥¤Ó [ ]¡¬___" << endl;
	cout << "¦¢                      ¦¢¦£¦ª¦¡¤Ó        ¦¢" << endl;
	cout << "¦¦¦¡£ï£ï¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥¦¦£ï£ï¦¡¦¡¦¡¦¡£ï¦¥" << endl;


    _bGGZ_ 
  R!          !R 
  B           `B 
hQQQQQQU
8QQ  QQ8
8QQLJQQ8
UQQQQQQU
*/