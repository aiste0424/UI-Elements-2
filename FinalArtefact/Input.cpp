#include "Input.h"

Input* Input::Instance()
{
	static Input* inputObject = new Input();
	return inputObject;
}

void Input::Update()
{
	while (SDL_PollEvent(&events))
	{

		if (events.type == SDL_QUIT)
		{
			m_isWindowClosed = true;
		}

		else if (events.type == SDL_KEYDOWN)
		{
			m_keyDown = events.key.keysym.sym;
		}

		else if (events.type == SDL_KEYUP)
		{
			m_keyDown = NULL;
			m_keyUp = events.key.keysym.sym;
		}

		else if (events.type == SDL_MOUSEBUTTONDOWN)
		{
			m_isMouseClicked = true;
			m_mouseButtonDown = events.button.button;
		}

		else if (events.type == SDL_MOUSEBUTTONUP)
		{
			m_isMouseClicked = false;
			m_mouseButtonUp = events.button.button;
		}

		else if (events.type == SDL_MOUSEMOTION)
		{
			m_mousePosition.x = events.motion.x;
			m_mousePosition.y = events.motion.y;
		}
	}
}

char Input::GetKeyUp()
{
	return m_keyUp;
}

char Input::GetKeyDown()
{
	return m_keyDown;
}

//checks if the left mouse button is clicked and returns true
//only the first frame when it happens instead of doing it continuously
bool Input::isLeftMouseButtonClicked()
{
	static bool leftButtonPressed = false;
	int x, y;
	Uint32 buttonState = SDL_GetMouseState(&x, &y);

	if (buttonState & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if (!leftButtonPressed) {
			leftButtonPressed = true;
			return true;
		}
	}
	else {
		leftButtonPressed = false;
	}
	return false;
}

bool Input::IsMouseClicked()
{
	return m_isMouseClicked;
}

bool Input::IsWindowClosed()
{
	return m_isWindowClosed;
}

SDL_Point& Input::GetMousePosition()
{
	return m_mousePosition;
}