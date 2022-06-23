#include <iostream> // 

//  [class] 5가지 특징 (OOP : Object-oriented programming) 객체지향 프로그래밍

//  1. ** 정보은닉
//			모든 데이터는 비공개 형태로 존재하며 요청과 승인과정을 거쳐 접근 (편의성을 위해 public 가능)
//  2. ** 캡슐화 (데이터와 함수의 집약)
//			기능은 공유할 수 없다 (같은 함수를 사용해도 객체마다 고유의 기능 사용)
//  3. ** 상속 
//			부모의 기능과 데이터를 자식이 사용할 수 있다, 다중 상속 웬만하면 회피
//  4. ** 추상화
//			특정되지 않음, 추상적인 클래스에서는 특정 객체가 존재하지 않으며 객체 생성의 틀로서 사용 
//  5. ** 다형성
//			다양한 형태로 존재할 수 있다


//  ** Getter & Setter 

//  ** namespace
//  ** 생성자 & 소멸자 & 복사생성자
//  ** 가상함수 & 순수가상함수
//  ** 오버로딩 & 오버라이딩
//  ** 연산자 오버로딩




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



int main(void)
{
	Object o1, o2;

	o1.Setter(10);
	o2.Setter(20);


	std::cout << o1.Getter() << std::endl;
	std::cout << o2.Getter() << std::endl;

	return 0;
}