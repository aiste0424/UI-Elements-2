#pragma once
#include <SDL.h>

class Input
{

public:

	static Input* Instance();
	void Update();

	char GetKeyUp();
	char GetKeyDown();

	bool isLeftMouseButtonClicked();
	bool IsMouseClicked();
	bool IsWindowClosed();
	SDL_Point& GetMousePosition();
	SDL_Event events;

private:

	Input() { }
	Input(const Input&);
	Input& operator=(Input&);

	char m_keyUp{ ' ' };
	char m_keyDown{ ' ' };

	bool m_isMouseClicked{ false };
	bool m_isWindowClosed{ false };

	int m_mouseButtonUp{ 1 };
	int m_mouseButtonDown{ 0 };

	SDL_Point m_mousePosition = { 0, 0 };
	
};