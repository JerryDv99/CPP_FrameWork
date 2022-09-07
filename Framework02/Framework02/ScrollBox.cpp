#include "ScrollBox.h"
#include "CursorManager.h"

ScrollBox::ScrollBox() : Width(0), Height(0)
{

}

ScrollBox::~ScrollBox()
{

}

void ScrollBox::Start()
{
	Key = "ScrollBox";

	/*Info.Position = Vector3(0.0f, 0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f, 0.0f);
	Info.Direction = Vector3(0.0f, 0.0f, 0.0f);*/

	Width = 2;
	Height = 1;

	//StartPos = Vector3(50, 10);
	EndPos = Vector3(StartPos.x + Width, StartPos.y + Height);


	WidthTexture = "";
	HeightTexture = (char*)"¦¢";

	ScrollBoxIndex = Index++;

	Texture.push_back("¦£¦¡¦¤");
	Texture.push_back("¦¢¡¡¦¢");
	Texture.push_back("¦¦¦¡¦¥");
	End = 3;
}

void ScrollBox::Update()
{

}

void ScrollBox::Render()
{
	for (int i = 0; i < Texture.size(); ++i)
		CursorManager::GetInstance()->WriteBuffer(StartPos.x, StartPos.y + i, Texture[i], ScrollBoxIndex == i ? 12 : 15);
}

void ScrollBox::Release()
{

}

/*if (GetAsyncKeyState(VK_CONTROL))
	{
		++Height;
		Width += 2;
		WidthTexture += "¦¡";
		EndPos = Vector3(StartPos.x + Width, StartPos.y + Height);
	}
	for (int y = StartPos.y  + 1; y < EndPos.y; ++y)
	{
		CursorManager::GetInstance()->WriteBuffer(StartPos.x, y, HeightTexture);
		CursorManager::GetInstance()->WriteBuffer(EndPos.x, y, HeightTexture);
	}
	CursorManager::GetInstance()->WriteBuffer(StartPos.x, StartPos.y, "¦£");
	CursorManager::GetInstance()->WriteBuffer(StartPos.x + 2, StartPos.y, WidthTexture);
	CursorManager::GetInstance()->WriteBuffer(StartPos.x, EndPos.y, "¦¦");
	CursorManager::GetInstance()->WriteBuffer(StartPos.x + 2, EndPos.y, WidthTexture);
	CursorManager::GetInstance()->WriteBuffer(EndPos.x, StartPos.y, "¦¤");
	CursorManager::GetInstance()->WriteBuffer(EndPos.x, EndPos.y, "¦¥");*/
