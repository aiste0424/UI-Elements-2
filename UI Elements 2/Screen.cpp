#include "Screen.h"
#include <iostream>

//creates screenObject once
Screen* Screen::Instance()
{
	static Screen* screenObject = new Screen();
	return screenObject;
}

bool Screen::Initialize(const std::string& windowTitle, const SDL_Point& dimension)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Error initializing SDL." << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow(windowTitle.c_str(),       //game window title
		SDL_WINDOWPOS_CENTERED,    //pos x
		SDL_WINDOWPOS_CENTERED,    //pos y
		dimension.x,                     //width
		dimension.y,                    //height
		0);

	if (!m_window)
	{
		std::cout << "Error creating game window." << std::endl;
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!m_renderer)
	{
		std::cout << "Error creating renderer." << std::endl;
		return false;
	}

	return true;
}

void Screen::Clear()
{
	SDL_RenderClear(m_renderer);
}

void Screen::Present()
{
	SDL_RenderPresent(m_renderer);
}

void Screen::Shutdown()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

SDL_Renderer* Screen::GetRenderer()
{
	return m_renderer;
}