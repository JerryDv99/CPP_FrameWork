#pragma once
#include "Headers.h"

class Object;

class MainUpdate
{
private:
	
public:
	void Start();	// �ʱ�ȭ
	void Update();	// ������� �� �浹 ���� �̺�Ʈ üũ
	void Render();	// �׸���
	void Release();	// �޸� ����
public:
	MainUpdate();
	~MainUpdate();
};

