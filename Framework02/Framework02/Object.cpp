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
	cout << "����ð� : ";
	cout << Time;
	cout << "�ð� ";
	cout << Minute;
	cout << "�� ";
	cout << Second;
	cout << "�� " << endl;
}

void Object::Release()
{

}
