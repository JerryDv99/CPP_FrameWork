#pragma once

// ** Singleton ('����, ������' ��ü)
// ** 1. ���� ��ü�� ������ (�ν��Ͻ��� �������� �������� ����)
// ** 2. ��𿡼��� ȣ�� ���� (������ ������ ���)

class Singleton
{
private:	// ������ ������ �ݴ� ������ �ƴ�
	static Singleton* Instance;	// (= new Singleton) static�� ������ ������ Instatnce�� , ���� Singleton* ���� �Ҵ��ϰ� Instance�� ����Ŵ
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
	Singleton() {}	// ���� ����
public:
	~Singleton() {}
};

// static : ���� ����, ���� �ּұ� ������ �ϳ��� ����, ������ ����
// ������ ������ ������ �ö󰡴� ���� RValue(���)����
// ���� ������ ����, static�̾ ���� ������ ���ÿ� ����