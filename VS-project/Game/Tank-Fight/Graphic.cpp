#include "Graphic.h"

int Graphic::m_screen_width = SCREEN_WIDTH;

int Graphic::m_screen_height = SCREEN_HEIGHT;

void Graphic::Create()
{

}

void Graphic::Destroy()
{

}

int Graphic::GetScreenWidth()
{
	return m_screen_width;
}

int Graphic::GetScreenHeight()
{
	return m_screen_height;
}