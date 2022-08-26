#include "Doomboo.h"
#include "CursorManager.h"
#include "Enemy.h"

Doomboo::Doomboo()
{
}

Doomboo::~Doomboo()
{
}

void Doomboo::Start()
{
}

int Doomboo::Update(Transform& _Transform)
{

	return 0;
}

void Doomboo::Render()
{
	CursorManager::GetInstance()->WriteBuffer(pObject->GetPosition(), (char*)"Doombop");
}

void Doomboo::Release()
{
}