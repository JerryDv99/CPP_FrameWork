#pragma once

// ** Singleton ('단일, 유일한' 개체)
// ** 1. 단일 객체로 구성됨 (인스턴스가 여러개로 구성되지 않음)
// ** 2. 어디에서나 호출 가능 (관리자 등으로 사용)

class Singleton
{
private:	// 동적과 정적은 반대 개념이 아님
	static Singleton* Instance;	// (= new Singleton) static은 데이터 영역에 Instatnce를 , 힙에 Singleton* 동적 할당하고 Instance를 가리킴
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Singleton;
		return Instance;
	}
private:
	string SceneState;
	
private:
	Singleton() {}	// 생성 제한
public:
	~Singleton() {}
};

// static : 정적 변수, 고정 주소기 때문에 하나만 존재, 데이터 영역
// 실제로 데이터 영역에 올라가는 값은 RValue(상수)뿐임
// 전역 변수는 힙에, static이어도 지역 변수는 스택에 존재