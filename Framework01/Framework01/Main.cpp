#include <iostream> // c++ ��Ÿ�� ǥ�� ����� ���̺귯��
#include <Windows.h>

//  ** �����Լ� & ���������Լ�
using namespace std;


//  ** ������ �����ε�

// ** Operator
class Object
{
private:
	int Number;
public:
	int GetNumber() { return Number; }
	/*
	Object& operator+=(Object& _obj) // operator�� ������ �����ε��� ���� ������ִ� ������
	{
		this->Number += _obj.Number;
		return (*this);
	}
	Object& operator+=(int _number) 
	{
		this->Number += _number; // this : ��ü �ڽ��� ����Ű�� ������
		return (*this);
	}
	*/
	Object& operator / (Object& _obj)
	{
		this->Number = this->Number / _obj.Number;
		return (*this);
	}
	/*Object& operator ++(Object& _obj)
	{
		++this->Number;
		return(*this);
	}*/
	Object& operator+(Object& _obj)
	{
		return Object(this->Number + _obj.Number);
		/*this->Number = this->Number + _obj.Number;
		return (*this);*/
	}
	/*Object& operator = (Object& _obj)
	{
		this->Number = _obj.Number;
		return(*this);
	}*/

public:
	Object() {}
	Object(int _number) : Number(_number) {}
	~Object() {}
	
};

int main(void)
{
	Object o1(4), o2(2);
	// o1 += o2;
	Object o3 = o1 + o2;
	//o1 + 7;
	//++o1;
	//o1 / o2;

	cout << o3.GetNumber() << endl;

	return 0;
}

//  [class] 5���� Ư¡ (OOP : Object-oriented programming) ��ü���� ���α׷���

//  1. ** ��������
//			��� �����ʹ� ����� ���·� �����ϸ� ��û�� ���ΰ����� ���� ���� (���Ǽ��� ���� public ����)
//  2. ** ĸ��ȭ (�����Ϳ� �Լ��� ����)
//			����� ������ �� ���� (���� �Լ��� ����ص� ��ü���� ������ ��� ���)
//  3. ** ��� 
//			�θ��� ��ɰ� �����͸� �ڽ��� ����� �� �ִ�, ���� ����� �����ϸ� ȸ��
//  4. ** �߻�ȭ
//			Ư������ ����, �߻����� Ŭ���������� Ư�� ��ü�� �������� ������ ��ü ������ Ʋ�μ� ���, �߻� Ŭ������ ��üȭ ��ų �� ������ ��ӽ��� �ڽ� Ŭ�������� ��ü ����
//  5. ** ������
//			�پ��� ���·� ������ �� �ִ�

//  ** Getter & Setter

/*
class Object
{
// ����� ���� (������)
private:
	int iNumber;

// ��Ӱ��� ������ ����
protected:


// ���� ���� (���)
public:

public:
	void Setter(int _Number) { iNumber = _Number; }	// �������� ���� ������ ���� �������� �ʰ� ���԰� ��ȯ ��ɸ� ����

	int Getter() { return iNumber; };
};
*/
/*
	Object o1, o2;

	o1.Setter(10);
	o2.Setter(20);


	std::cout << o1.Getter() << std::endl;
	std::cout << o2.Getter() << std::endl;
*/
//  ** namespace

/*
class Object
{
private:
	int Number;	// static ������ ��� ��ü�� �����ϴ� �ϳ��� ����

public:
	void Output();	// Ŭ���� �ȿ��� ���ǵ� �Լ��� Ư���� ��ġ�� ���ϱ� ������ �Ϲ� �Լ��� ���� �ϰ� �ܺ�(Ŭ������ ���弱)���� �����Ѵ� ( + ������)
};

void Object::Output()
{
	printf_s("Object : %d\n", 0);
}
*/

/*
namespace AAA	// ������ ������ ����� ������ ������ �ʴ´�, ���� �̸��� �Լ� ��� ����,  '::'���� �����ؾ� �� Ŭ������ namespace�ȿ� ���Ե� �� �ִ�
{
	int Number;
	void Output()
	{
		printf_s("AAA : %d\n", Number);
	}
}
using namespace::function; namespace�� �����ϰ� �Լ��� �� �� �ִ�. ���� x
*/

//  ** ������ & �Ҹ��� & ���������

/*
class Object
{
private:
	tagInfo Info;
	int Number;
	//Object() {} �����ڰ� private�� �����ڿ� ������ �� ����
public:
	// ** ������ & �Ҹ��� : ������ ȣ���� ������ �ڵ����� ȣ���
	Object() : Number(0)
	{
		// ** ������
		cout << "������" << endl;
	}

	~Object()
	{
		// ** �Ҹ��� (~Ŭ����)
		cout << "�Ҹ���" << endl;
	}

	// ��������ڴ� ����ڰ� ���� ȣ���� ��쿡�� ȣ��, �������� ���� �����ϸ� �̋� ���³� ������ �ٸ� �Ű������� ���� ������ �Ǿ�� ��
	Object(string _str) : Number(0)
	{
		// ** ���� ������
		cout << _str << endl;
	}

	Object(string _str, int _i) : Number(_i)
	{
		// ** ���� ������
		Number = _i;
		cout << _str << ":" << Number << endl;
	}

};*/

/*
class Player : public Object
{
public:
	Player() {}

	Player(tagInfo _Info) : Object(_Info) // �����ڿ����� ��ӹ��� �θ��� private�� ������ �Ұ���
	{

	}

	~Player() {}
};
*/

/*
int main(void)
{
	// �����ڴ� ����� ���ÿ� ȣ��
	Object o; // = Object(); ������ ȣ�� ����


	return 0; // ������ ȣ���� ������ �Ҹ��ڴ� ���α׷� ����� ȣ��
}*/

/* ������
class Parent
{
protected:
	string Name;
public:
	virtual void Output() = 0;

	Parent() {};
	Parent(string _str) : Name(_str) {};
};

class Child : public Parent	// Child�� Parent���� ��ӹ���
{
public:
	void Output()
	{
		cout << Name << endl;	// �θ� Ŭ�������� ��Ӱ��� ���� ������ protected ������ ��� ����
	}
public:
	Child() {}
	Child(string _str) : Parent(_str) {}
};

class Object : public Parent
{
public:
	void Output()
	{
		cout << Name << endl;
	}
public:
	Object(string _str) : Parent(_str) {}
};


// ** ������
Parent* p[2];

p[0] = new Child("Child");
p[1] = new Object("Object");

for (int i = 0; i < 2; ++i)
	p[i]->Output();
*/

// ** ���
/*
class Parent
{
protected:
	string Name;
public:
	void Output() { cout << Name << endl; }

	Parent() {}
	Parent(string _str) : Name(_str) {}
};

class Child : public Parent
{
public:
	Child() {}
	Child(string _str) : Parent(_str) {}
};

class Object : public Parent
{
public:
	Object() {}
	Object(string _str) : Parent(_str) {}
};




Child c = Child("Child");
	c.Output();				// �θ��� �Լ� ��� ����
	Object o = Object("Object");
	o.Output();
*/

//  ** �����ε� & �������̵�
// �����ε� : ���� �������� ���� �̸��̶� �Ű������� ������ ���¿� ���� �ٸ��� ��� ����
// �������̵� : [��Ӱ����� ��] �̸��� ���� �Լ� �� � �Լ��� ȣ���� ���ΰ��� Ŭ���� ���¿� ����, �ڽ� Ŭ���������� �Լ� ������
//  ** ��� & ������
/*
class Parent
{
protected:
	string Name;
public:
	virtual void Output()PURE; // virtual�� new �Ҵ��� ��ü�� �Լ��� ����ϰ� ����, �����Լ��� 0(=0)�� �� �ִ� -> ���� �����Լ� PURE

	Parent() {}
	Parent(string _str) : Name(_str) {}
	virtual void Output()PURE;
	virtual void Output(string _str)PURE;
};

class Child : public Parent
{
public:
	void Output() { cout << "Child : " << Name << endl; }	// virtual�� ������ �ʾƵ� �����Լ��� �ν�
	void Output(string _str) override { cout << "Child : " << Name << endl; }
public:
	Child() {}
	Child(string _str) : Parent(_str) {}
};

class Object : public Parent
{
public:
	void Output() { cout << "Object : " << Name << endl; }
	void Output(string _str) override { cout << "Object : " << Name << endl; }
public:
	Object() {}
	Object(string _str) : Parent(_str) {}
};
main
Parent* p[2];
	p[0] = new Child("ȫ�浿");
	p[1] = new Object("�Ӳ���");

*/
/*
	int i = 10;
	cout << (i << 1) << endl; // ��Ʈ�����̶� ������
	cout << (i * 2) << endl;

	cout << endl;

	cout << (i >> 1) << endl; **
	cout << (i / 2) << endl;
	*/

	// ** [&] ��� �뵵

	// ** 1. 2�� �����ڷ� ��� 
	//		- & <- 1���� �����ٸ� [��Ʈ����]
	//		- && <- 2�� �����ٸ� [��(��)����]

	// ** 2. ���� �����ڷ� ��� 
	//		- &����  <- ���� ���ʿ� ���� ��� [�ּҹ�ȯ ������]
	//		- �ڷ���(����)& <- �ڷ��� ���ʿ� ���� ��� [���۷��� ������]
	//						  ���� �������� �ʰ� �ش� �ڷ��� ��ü�� ���
	/*
	int Add(const int _i)
	{
		return _i + 1;
	}

	int main(void)
	{
		int i = 10;
		int n = Add(i);
		cout << n << endl;
		return 0;
	}
	*/
