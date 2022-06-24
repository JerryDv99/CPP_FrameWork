#include <iostream> // c++ 스타일 표준 입출력 라이브러리
#include <Windows.h>


//  ** 가상함수 & 순수가상함수
//  ** 연산자 오버로딩
using namespace std;

//  ** 오버로딩 & 오버라이딩 
// 오버로딩 : 같은 영역에서 같은 이름이라도 매개변수의 개수와 형태에 따라 다르게 사용 가능
// 오버라이딩 : [상속관계일 때] 이름이 같은 함수 중 어떤 함수를 호출할 것인가는 클래스 형태에 따름, 자식 클래스의 함수 재정의
//  ** 상속 & 다형성
class Parent
{
protected:
	string Name;
public:
	virtual void Output()PURE;
	virtual void Output(string _str)PURE;

	Parent() {}
	Parent(string _str) : Name(_str) {}
};

class Child : public Parent
{
public:
	void Output() { cout << "Child : " << Name << endl; }	
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

int main(void)
{
	Parent* p[2];
	p[0] = new Child("홍길동");
	p[1] = new Object("임꺽정"); 

	return 0;
}

//  [class] 5가지 특징 (OOP : Object-oriented programming) 객체지향 프로그래밍

//  1. ** 정보은닉
//			모든 데이터는 비공개 형태로 존재하며 요청과 승인과정을 거쳐 접근 (편의성을 위해 public 가능)
//  2. ** 캡슐화 (데이터와 함수의 집약)
//			기능은 공유할 수 없다 (같은 함수를 사용해도 객체마다 고유의 기능 사용)
//  3. ** 상속 
//			부모의 기능과 데이터를 자식이 사용할 수 있다, 다중 상속은 웬만하면 회피
//  4. ** 추상화
//			특정되지 않음, 추상적인 클래스에서는 특정 객체가 존재하지 않으며 객체 생성의 틀로서 사용, 추상 클래스는 객체화 시킬 수 없으며 상속시켜 자식 클래스에서 객체 생성
//  5. ** 다형성
//			다양한 형태로 존재할 수 있다

//  ** Getter & Setter

/*
class Object
{
// 비공개 형태 (데이터)
private:
	int iNumber;

// 상속간의 접근이 가능
protected:


// 공개 형태 (기능)
public:

public:
	void Setter(int _Number) { iNumber = _Number; }	// 안정성을 위해 변수에 직접 접근하지 않고 대입과 반환 기능만 구현

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
	int Number;	// static 변수는 모든 객체가 공유하는 하나의 변수

public:
	void Output();	// 클래스 안에서 정의된 함수는 특별한 가치를 지니기 때문에 일반 함수는 선언만 하고 외부(클래스의 연장선)에서 정의한다 ( + 가독성)
};

void Object::Output()
{
	printf_s("Object : %d\n", 0);
}
*/

/*
namespace AAA	// 별도의 영역을 만들어 간섭이 생기지 않는다, 같은 이름의 함수 사용 가능,  '::'으로 접근해야 함 클래스도 namespace안에 포함될 수 있다
{
	int Number;
	void Output()
	{
		printf_s("AAA : %d\n", Number);
	}
}
using namespace::function; namespace를 제외하고 함수명만 쓸 수 있다. 남용 x
*/

//  ** 생성자 & 소멸자 & 복사생성자

/*
class Object
{
private:
	tagInfo Info;
	int Number;
	//Object() {} 생성자가 private면 생성자에 접근할 수 없다
public:
	// ** 생성자 & 소멸자 : 별도의 호출이 없더라도 자동으로 호출됨
	Object() : Number(0)
	{
		// ** 생성자
		cout << "생성자" << endl;
	}

	~Object()
	{
		// ** 소멸자 (~클래스)
		cout << "소멸자" << endl;
	}

	// 복사생성자는 사용자가 직접 호출한 경우에만 호출, 여러개가 존재 가능하며 이떄 형태나 개수가 다른 매개변수를 가져 구분이 되어야 함
	Object(string _str) : Number(0)
	{
		// ** 복사 생성자
		cout << _str << endl;
	}

	Object(string _str, int _i) : Number(_i)
	{
		// ** 복사 생성자
		Number = _i;
		cout << _str << ":" << Number << endl;
	}

};*/

/*
class Player : public Object
{
public:
	Player() {}

	Player(tagInfo _Info) : Object(_Info) // 생성자에서는 상속받은 부모의 private에 접근이 불가함
	{

	}

	~Player() {}
};
*/

/*
int main(void)
{
	// 생성자는 선언과 동시에 호출
	Object o; // = Object(); 생성자 호출 과정


	return 0; // 별도의 호출이 없으면 소멸자는 프로그램 종료시 호출
}*/

/* 다형성
class Parent
{
protected:
	string Name;
public:
	virtual void Output() = 0;

	Parent() {};
	Parent(string _str) : Name(_str) {};
};

class Child : public Parent	// Child는 Parent에게 상속받음
{
public:
	void Output()
	{
		cout << Name << endl;	// 부모 클래스에서 상속간에 접근 가능한 protected 변수들 사용 가능
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


// ** 다형성
Parent* p[2];

p[0] = new Child("Child");
p[1] = new Object("Object");

for (int i = 0; i < 2; ++i)
	p[i]->Output();
*/

// ** 상속
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
	c.Output();				// 부모의 함수 사용 가능
	Object o = Object("Object");
	o.Output();
*/

//  ** 오버로딩 & 오버라이딩 
//  ** 상속 & 다형성
/*
class Parent
{
protected:
	string Name;
public:
	virtual void Output()PURE; // virtual은 new 할당한 개체의 함수를 사용하게 해줌, 가상함수는 0(=0)일 수 있다 -> 순수 가상함수 PURE

	Parent() {}
	Parent(string _str) : Name(_str) {}
};

class Child : public Parent
{
public:
	void Output() { cout << "Child : " << Name << endl; }	// virtual을 써주지 않아도 가상함수로 인식
public:
	Child() {}
	Child(string _str) : Parent(_str) {}
};

class Object : public Parent
{
public:
	void Output() { cout << "Object : " << Name << endl; }
public:
	Object() {}
	Object(string _str) : Parent(_str) {}
};
*/
