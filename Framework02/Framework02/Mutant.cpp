#include "Mutant.h"
#include "CursorManager.h"
#include "Enemy.h"

Mutant::Mutant()
{
}

Mutant::~Mutant()
{
}

void Mutant::Start()
{
}

int Mutant::Update(Transform& _Transform)
{
	return 0;
}

void Mutant::Render()
{
	CursorManager::GetInstance()->WriteBuffer(pObject->GetPosition(), (char*)"Mutant");
}

void Mutant::Release()
{
}