#include "MainUpdate.h"



int main(void)
{
	system("title �垮瘚� : 啪歜檜葷");
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
	cout << "忙\"LSPD`式忖" << endl;
	cout << "戌�鵀’﹝鵀�" << endl;

	cout << "忙式式式式**忖" << endl;
	cout << "弛       弛 弛___" << endl;
	cout << "弛 LSPD         弛" << endl;
	cout << "戌式�鵀’’’﹝鵀�" << endl;

	cout << "∞  ∞" << endl;
	cout << "  ﹥" << endl;
	cout << "∞  ∞" << endl;

	cout << "≡  ≡" << endl;
	cout << "  ﹥" << endl;
	cout << "≡  ≡" << endl;

	cout << "≒  ≒" << endl;
	cout << "  ﹥" << endl;
	cout << "≒  ≒" << endl;






	cout << "   ____" << endl;
	cout << "忙◣   `式忖" << endl;
	cout << "戌�鵀’﹝鵀�" << endl;

	cout << "     ____" << endl;
	cout << "忙式◣   `忖" << endl;
	cout << "戌�鵀’﹝鵀�" << endl;

	cout << " ___________" << endl;
	cout << "弛         ]′_" << endl;
	cout << "弛            弛" << endl;
	cout << "戌式�鵀’’﹝鵀�" << endl;
	
	cout << "   ____________" << endl;
	cout << " _/ [         弛" << endl;
	cout << "弛            弛" << endl;
	cout << "戌�鵀’’﹝鵀’�" << endl;






	cout << "    _____" << endl;
	cout << "忙-◣  螃`式忖" << endl;
	cout << "戌-�鵀’�-�鵀�" << endl;

	cout << "        ____" << endl;
	cout << "式成 褡太  ]′_" << endl;
	cout << "忙扛-扛戎     弛" << endl;
	cout << "戌式�鵀’’﹝鵀�" << endl;

	cout << "忙式式式式式式式式式式式式式式忖太____" << endl;
	cout << "弛                      忙式成戎太 [ ]′___" << endl;
	cout << "弛                      弛忙扛式太        弛" << endl;
	cout << "戌式�鵃鵀’’’’’’’’它忙鵃鵀’’’﹝鵀�" << endl;


    _bGGZ_ 
  R!          !R 
  B           `B 
hQQQQQQU
8QQ  QQ8
8QQLJQQ8
UQQQQQQU
*/