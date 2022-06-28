#include "Headers.h"

// ** Singleton ('단일, 유일한' 개체)
// static : 정적 변수, 고정 주소기 때문에 하나만 존재, 데이터 영역
// 실제로 데이터 영역에 올라가는 값은 RValue(상수)뿐임
// 전역 변수는 힙에, static이어도 지역 변수는 스택에 존재
class Singleton
{
private:	// 동적과 정적은 반대 아님
	static Singleton* Instance;	// (= new Singleton) static은 데이터 영역에 Instatnce를 , 힙에 Singleton* 동적 할당하고 static을 가리킴
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new Singleton;
		return Instance;
	}

	int Number;
};

Singleton* Singleton::Instance = nullptr;



int main(void)
{
	static Singleton* Instance = new Singleton;

	// ** 최초에 생성 후 초기화
	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();
	
	while (true)
	{
		if (Time + 1000 <= GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			// ** 변경사항 및 충돌 등의 이벤트 체크
			Main.Update();

			// ** 그리기
			Main.Render();

			
		}
	}

	return 0;
}

// ** DWORD unsigned long
// ** ULONGLONG unsigned __int64 
// DWORD dwTime = GetTickCount();
//				1 / 1000초	max 49일
//				1 / 1000초	max 500년
