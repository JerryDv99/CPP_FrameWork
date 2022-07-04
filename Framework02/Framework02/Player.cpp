#include "Player.h"
#include "InputManager.h"

Player::Player()
{
}
Player::~Player()
{
}

void Player::Start()
{

}

void Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	
	cout << "x : " << Info.Position.x << endl;
	cout << "y : " << Info.Position.y << endl;

	if (dwKey & KEY_UP)
	{
		cout << "KEY_UP" << endl;
		Info.Position.y++;
	}

	if (dwKey & KEY_DOWN)
	{
		cout << "KEY_DOWN" << endl;
		Info.Position.y--;
	}

	if (dwKey & KEY_LEFT)
	{
		cout << "KEY_LEFT" << endl;
		Info.Position.x--;
	}

	if (dwKey & KEY_RIGHT)
	{
		cout << "KEY_RIGHT" << endl;
		Info.Position.x++;
	}

	if (dwKey & KEY_SPACE)
		cout << "KEY_SPACE" << endl;

	if (dwKey & KEY_RETURN)
		cout << "KEY_RETURN" << endl;

	if (dwKey & KEY_ESCAPE)
		cout << "KEY_ESCAPE" << endl;
}

void Player::Render()
{

}

void Player::Release()
{

}