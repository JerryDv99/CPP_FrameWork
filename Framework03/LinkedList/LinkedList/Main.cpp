#include <iostream>


using namespace std;

struct Node
{
	Node* Front;
	int Value;
	Node* Back;
};
/*
class Node
{
public:
	int Value;
};
*/

int Size = 0;

void Output(Node* _pList);
void push_back(Node* _pList, int _Value);
void insert(Node* _pList, int _Where, int _Value);
void erase(Node* _pList, int _Where);

int main(void)
{
	Node* pList = new Node;
	pList->Front = nullptr;
	pList->Value = 10;
	pList->Back = nullptr;

	/*
	{
		pList->Back = new Node;

		pList->Back->Value = 20;
		pList->Back->Back = nullptr;
	}

	{
		pList->Back->Back = new Node;

		pList->Back->Back->Value = 30;
		pList->Back->Back->Back = nullptr;
	}

	{
		pList->Back->Back->Back = new Node;

		pList->Back->Back->Back->Value = 40;
		pList->Back->Back->Back->Back = nullptr;
	}

	cout << pList->Value << endl;
	cout << pList->Back->Value << endl;
	cout << pList->Back->Back->Value << endl;
	cout << pList->Back->Back->Back->Value << endl;
	*/

	for (int i = 0; i < 10; ++i)
		push_back(pList, (i + 2) * 10);

	erase(pList, 3);
	insert(pList, 3, 25);

	Output(pList);
	return 0;
}

void Output(Node* _pList)
{
	/*
	cout << _pList->Value << endl;

	if (_pList->Back != nullptr)
		Output(_pList->Back);
	*/
	Node* pNode = _pList;

	while (true)
	{
		if (pNode != nullptr)
		{
			cout << pNode->Value << endl;
			pNode = pNode->Back;
		}
		else
			break;
	}
}

void push_back(Node* _pList, int _Value)
{
	/*int Temp;

	cin >> Temp;

	_pList->Value = Temp;*/	

	Node* pNode = _pList;

	while (true)
	{
		if (pNode->Back == nullptr)
		{
			Node* ppNode = new Node;

			ppNode->Front = pNode;
			//cout << "입력 : "; cin >> _pList->Value;

			ppNode->Value = _Value;
			ppNode->Back = nullptr;

			pNode->Back = ppNode;

			Size += 1;
			break;
		}
		else
		{
			pNode = pNode->Back;
		}
	}
	
	/*
	if (_pList->Back == nullptr)
	{
		Node* pNode = new Node;

		pNode->Front = _pList;
		//cout << "입력 : "; cin >> _pList->Value;

		pNode->Value = _Value;
		pNode->Back = nullptr;

		_pList->Back = pNode;
		
		Size += 1;
	}

	else
		push_back(_pList->Back, _Value);
	*/
	
}

void insert(Node* _pList, int _Where, int _Value)
{
	Node* pNode = _pList;
	int Where = _Where;
	while (true)
	{
		if (Size >= Where && Where == 1)
		{
			Node* ppNode = new Node;
			ppNode->Value = _Value;

			ppNode->Front = pNode->Front;
			pNode->Front->Back = ppNode;
			ppNode->Back = pNode;
			pNode->Front = ppNode;

			Size += 1;
			break;
		}
		else
		{
			Where -= 1;
			pNode = pNode->Back;
		}
	}
	/*
	if (Size >= _Where && _Where == 1)
	{
		Node* pNode = new Node;
		pNode->Value = _Value;

		pNode->Front = _pList->Front;
		_pList->Front->Back = pNode;
		pNode->Back = _pList;
		_pList->Front = pNode;

		Size +=1;
	}
	else
		insert(_pList->Back, _Where - 1, _Value);
	*/
}

void erase(Node* _pList, int _Where)
{
	Node* pNode = _pList;
	int Where = _Where;

	while (true)
	{
		if (Size >= Where && Where == 1)
		{
			pNode->Back->Front = pNode->Front;
			pNode->Front->Back = pNode->Back;


			delete pNode;
			break;
		}
		else
		{
			pNode = pNode->Back;
			Where -= 1;
		}
	}
	/*
	if (Size >= _Where && _Where == 1)
	{
		// 노드 연결
		_pList->Back->Front = _pList->Front;
		_pList->Front->Back = _pList->Back;


		delete _pList;
	}
	else
		erase(_pList->Back, _Where - 1);
	*/
}