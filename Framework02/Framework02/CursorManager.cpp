#include "CursorManager.h"

CursorManager* CursorManager::Instance = nullptr;

CursorManager::CursorManager(): BufferIndex(0)
{
}

CursorManager::~CursorManager()
{
	DestroyBuffer();
}

// 버퍼 생성
void CursorManager::CreateBuffer(const int& _Width, const int& _Height)
{
	CONSOLE_CURSOR_INFO CursorInfo;

	// 커서를 안보이게 함
	CursorInfo.bVisible = FALSE;
	CursorInfo.dwSize = 1;

	COORD Size = { SHORT(_Width - 1),  SHORT(_Height - 1) };

	SMALL_RECT Rect = { 0, 0, SHORT(_Width),  SHORT(_Height) };

	HBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(HBuffer[0], Size);
	SetConsoleWindowInfo(HBuffer[0], TRUE, &Rect);
	SetConsoleCursorInfo(HBuffer[0], &CursorInfo);

	HBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(HBuffer[1], Size);
	SetConsoleWindowInfo(HBuffer[1], TRUE, &Rect);
	SetConsoleCursorInfo(HBuffer[1], &CursorInfo);
}

// 버퍼에 쓰기
void CursorManager::WriteBuffer(float _x, float _y, char* _str, int _Color)
{
	COORD CursorPosition = { (SHORT)_x, (SHORT)_y };

	// 위치
	SetConsoleCursorPosition(HBuffer[BufferIndex], CursorPosition);

	SetColor(_Color);

	DWORD dw = 0;

	// 버퍼, 내용 출력
	WriteFile(HBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}
void CursorManager::WriteBuffer(Vector3 _Position, char* _str, int _Color)
{
	COORD CursorPosition = { _Position.x, _Position.y };

	SetColor(_Color);

	SetConsoleCursorPosition(HBuffer[BufferIndex], CursorPosition);

	DWORD dw = 0;

	WriteFile(HBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void CursorManager::WriteBuffer(float _x, float _y, string _string, int _Color)
{
	COORD CursorPosition = { (SHORT)_x , (SHORT)_y };

	SetConsoleCursorPosition(HBuffer[BufferIndex], CursorPosition);

	SetColor(_Color);

	DWORD dw;

	char* _str = (char*)_string.c_str();

	WriteFile(HBuffer[BufferIndex], _str, (DWORD)strlen(_str), &dw, NULL);
}

void CursorManager::WriteBuffer(float _x, float _y, int _Value, int _Color)
{
	COORD CursorPosition = { (SHORT)_x , (SHORT)_y };

	SetConsoleCursorPosition(HBuffer[BufferIndex], CursorPosition);

	SetColor(_Color);

	DWORD dw;


	//char Buffer[128] = "";

	char* Buffer = new char[sizeof(int)];

	_itoa(_Value, Buffer, 10);



	WriteFile(HBuffer[BufferIndex], Buffer, (DWORD)strlen(Buffer), &dw, NULL);
}

void CursorManager::WriteBuffer(float _x, float _y, float _Value, int _Color)
{
	COORD CursorPosition = { (SHORT)_x , (SHORT)_y };

	SetConsoleCursorPosition(HBuffer[BufferIndex], CursorPosition);

	SetColor(_Color);

	DWORD dw;


	//char Buffer[128] = "";

	char* Buffer = new char[sizeof(int)];

	_itoa(_Value, Buffer, 10);



	WriteFile(HBuffer[BufferIndex], Buffer, (DWORD)strlen(Buffer), &dw, NULL);
}

void CursorManager::WriteBuffer(Vector3 _Position, int _Value, int _Color)
{
	COORD CursorPosition = { (SHORT)_Position.x , (SHORT)_Position.y };

	SetConsoleCursorPosition(HBuffer[BufferIndex], CursorPosition);

	SetColor(_Color);

	DWORD dw;

	char* Buffer = new char[sizeof(int)];

	_itoa(_Value, Buffer, 10);

	WriteFile(HBuffer[BufferIndex], Buffer, (DWORD)strlen(Buffer), &dw, NULL);
}

// 버퍼 전환
void CursorManager::FlippingBuffer()
{
	// 선택된 버퍼 보여줌
	SetConsoleActiveScreenBuffer(HBuffer[BufferIndex]);

	// 버퍼 인덱스를 변경
	BufferIndex = !BufferIndex;

	ClearBuffer();
}

// 버퍼 지우기
void CursorManager::ClearBuffer()
{
	COORD Coord = { 0, 0 };
	DWORD dw = 0;

	// 버퍼를 ' '라는 공백으로 채움
	FillConsoleOutputCharacter(HBuffer[BufferIndex], ' ', 150 * 40, Coord, &dw);
}

// 버퍼 해제
void CursorManager::DestroyBuffer()
{
	CloseHandle(HBuffer[0]);
	CloseHandle(HBuffer[1]);
}


void CursorManager::SetColor(int _Color)
{
	
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _Color);
	SetConsoleTextAttribute(HBuffer[BufferIndex], _Color);
}


