#include "Object.h"

Object::Object()
{
}
Object::~Object()
{
}

void Object::Start()
{
	Time = 0;
	Minute = 0;
	Second = 0;
}

void Object::Update()
{
	++Second;
	if (Second == 60)
	{
		Second = 0;
		++Minute;
	}
	if (Minute == 60)
	{
		Minute = 0;
		++Time;
	}
}

void Object::Render()
{
	cout << "경과시간 : ";
	cout << Time;
	cout << "시간 ";
	cout << Minute;
	cout << "분 ";
	cout << Second;
	cout << "초 " << endl;
}

void Object::Release()
{

}
