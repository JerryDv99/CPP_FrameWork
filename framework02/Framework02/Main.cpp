#include "MainUpdate.h"



int main(void)
{
	system("title ȫ�浿 : �����̸�");
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
	cout << "��\"LSPD`����" << endl;
	cout << "���說���殮" << endl;

	cout << "����������**��" << endl;
	cout << "��       �� ��___" << endl;
	cout << "�� LSPD         ��" << endl;
	cout << "�����說�������殮" << endl;

	cout << "��  ��" << endl;
	cout << "  ��" << endl;
	cout << "��  ��" << endl;

	cout << "��  ��" << endl;
	cout << "  ��" << endl;
	cout << "��  ��" << endl;

	cout << "��  ��" << endl;
	cout << "  ��" << endl;
	cout << "��  ��" << endl;






	cout << "   ____" << endl;
	cout << "����   `����" << endl;
	cout << "���說���殮" << endl;

	cout << "     ____" << endl;
	cout << "������   `��" << endl;
	cout << "���說���殮" << endl;

	cout << " ___________" << endl;
	cout << "��         ]��_" << endl;
	cout << "��            ��" << endl;
	cout << "�����說�����殮" << endl;
	
	cout << "   ____________" << endl;
	cout << " _/ [         ��" << endl;
	cout << "��            ��" << endl;
	cout << "���說�����說��" << endl;






	cout << "    _____" << endl;
	cout << "��-��  ��`����" << endl;
	cout << "��-�說��-�殮" << endl;

	cout << "        ____" << endl;
	cout << "���� �ʤ�  ]��_" << endl;
	cout << "����-����     ��" << endl;
	cout << "�����說�����殮" << endl;

	cout << "����������������������������������____" << endl;
	cout << "��                      ���������� [ ]��___" << endl;
	cout << "��                      ����������        ��" << endl;
	cout << "������說��������������������說�������殮" << endl;


    _bGGZ_ 
  R!          !R 
  B           `B 
hQQQQQQU
8QQ  QQ8
8QQLJQQ8
UQQQQQQU
*/