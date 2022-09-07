#include <iostream>
#include <list>
#include <vector>
#include <Windows.h>


using namespace std;

bool Compare(int _Temp, int _Dest);

int main(void)
{
	// iterator (�ݺ���) 1
	/*
	{
		int Array[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

		int* iter = Array;

		for (int i = 0; i < 8; ++i)
			cout << *(iter + i) << endl;
	}
	*/

	// iterator 2
	/*
	{
		int Array[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };

		int* iter = Array;

		for (int i = 0; i < 8; ++i)
			cout << *(iter++) << endl;
	}
	*/


	// iterator 3
	/*
	{
		list<int> Numbers;

		Numbers.push_back(10);
		Numbers.push_back(20);
		Numbers.push_back(30);
		Numbers.push_back(40);
		Numbers.push_back(50);

		list<int>::iterator iter = Numbers.begin();


		for (int i = 0; i < 5; ++i)
		{
			cout << *(iter++) << endl;
		}
		cout << endl;
	}
	*/
	
	// iterator 4
	/*
	{
		list<int> Numbers;

		Numbers.push_back(10);
		Numbers.push_back(20);
		Numbers.push_back(30);
		Numbers.push_back(40);
		Numbers.push_back(50);

		for (list<int>::iterator iter = Numbers.begin();
			iter != Numbers.end(); ++iter)
			cout << *iter << endl;
		cout << endl;
	}
	*/

	
	//----------

	// List �Լ�

	{
		list<int> Numbers;

		// ù��° ���Ҹ� ����Ű�� �ݺ���
		//Numbers.begin();

		// ù��° ���� ��ȯ
		//Numbers.front();

		// �������� ����Ű�� �ݺ���
		//Numbers.end();

		// ������ ���� ��ȯ
		//Numbers.back();



		// ù��° ��ġ�� ���� �߰�
		//Numbers.push_front();
		
		// ������ ��ġ�� ���� �߰�
		//Numbers.push_back();

		// ������ ��ġ _Where�� �� value �߰�
		// _Where�� �ݺ���
		//Numbers.insert(_Where (iter), value);

		// �ݺ��ڰ� �ִ� ��ġ�� ���Ҹ� �����ϰ� ���� �ݺ��� ��ȯ
		//iter = Numbers.erase(iter);


		// ù��° ���� ����
		//Numbers.pop_front();

		// ������ ���� ����
		//Numbers.pop_back();

		// ��ü ���� ����
		//Numbers.clear();



		// ���� ����� �� ���� ��ȯ
		//Numbers.size();

		// ** ����Ʈ�� ���� �ִ��� ������ (�������) Ȯ�� 
		//Numbers.empty();
		/*
		for(int i = 0; i<2; ++i)
		{
			if(Numbers.empty())
			{
				cout << "False : �����Ͱ� ���� �˴ϴ�." << endl;
				Numbers.push_back(10);
			}
			else
			{
				cout << "True : ���" << endl;
				for (list<int>::iterator iter = Numbers.begint();
				iter != Numbers.end(); ++iter)
					cout << *iter << endl;
			}

			cout << endl;
		}
		*/

		// ����Ʈ�� �����Ѵ�
		//Numbers.sort();
		/*
		{
			for (int i = 0; i < 10; ++i)
			{
				srand(GetTickCount64() * (i + 1));
				Numbers.push_back(rand() % 100 + 1);
			}

			cout << "[���� ��]" << endl;
			for (list<int>::iterator iter = Numbers.begin();
				iter != Numbers.end(); ++iter)
				cout << *iter << endl;
			cout << endl;

			Numbers.sort(Compare);

			cout << "[���� ��]" << endl;
			for (list<int>::iterator iter = Numbers.begin();
				iter != Numbers.end(); ++iter)
				cout << *iter << endl;
			cout << endl;
		}
		*/
	}

	// vector �Լ�
	{
		vector<int> Numbers;

		// ù��° ���Ҹ� ����Ű�� �ݺ���
		//Numbers.begin();

		// ù��° ���� ��ȯ
		//Numbers.front();

		// �������� ����Ű�� �ݺ���
		//Numbers.end();

		// ������ ���� ��ȯ
		//Numbers.back();


		// ������ ��ġ�� ���� �߰�
		//Numbers.push_back();

		// ������ ��ġ _Where�� �� value �߰�
		// _Where�� �ݺ���
		//Numbers.insert(_Where (iter), value);

		// �ݺ��ڰ� �ִ� ��ġ�� ���Ҹ� �����ϰ� ���� �ݺ��� ��ȯ
		//iter = Numbers.erase(iter);



		// ������ ���� ����
		//Numbers.pop_back();

		// ��ü ���� ����
		//Numbers.clear();



		// ���� ����� �� ���� ��ȯ
		//Numbers.size();

		// ��尡 ���Ե� �� �ִ� ��������
		//Numbers.capacity();

		// �迭ó�� ���� ����
		//Numbers[Index]
		
		/*
		// int
		{
			for (int i = 0; i < 10; ++i)
				Numbers.push_back(i * 10 + 10);
			for (int i = 0; i < 10; ++i)
				cout << Numbers[i] << endl;
		}
		cout << endl;
		*/

		/*
		// size_t
		{
			for (int i = 0; i < 10; ++i)
				Numbers.push_back(i * 10 + 10);
			for (size_t i = 0; i < Numbers.size(); ++i)
				cout << Numbers[i] << endl;
		}
		cout << endl;
		*/

		/*
		// iterator
		{
			for (int i = 0; i < 10; ++i)
				Numbers.push_back(i * 10 + 10);

			for (vector<int>::iterator iter = Numbers.begin();
				iter != Numbers.end(); ++iter)
				cout << *iter << endl;
		}
		cout << endl;
		*/


		// ** ����Ʈ�� ���� �ִ��� ������ (�������) Ȯ�� 
		//Numbers.empty();
		/*
		for(int i = 0; i<2; ++i)
		{
			if(Numbers.empty())
			{
				cout << "False : �����Ͱ� ���� �˴ϴ�." << endl;
				Numbers.push_back(10);
			}
			else
			{
				cout << "True : ���" << endl;
				for (vector<int>::iterator iter = Numbers.begint();
				iter != Numbers.end(); ++iter)
					cout << *iter << endl;
			}

			cout << endl;
		}
		*/		
	}    
	return 0;
}

bool Compare(int _Temp, int _Dest)
{
	return _Temp > _Dest;
}