#include <SDL.h>
#include <iostream>

#include "Checkbox.h"
#include "Screen.h"
#include "Input.h"

int main(int argc, char* argv[])
{
	bool isGameRunning = true;
	Checkbox checkbox;
	
	
	if (!Screen::Instance()->Initialize("Test", { 1280, 720 }))
	{
		std::cout << "Screen failed to initialize" << std::endl;
		return 0;
	}
	
	while (isGameRunning)
	{
		Screen::Instance()->Clear();
		Input::Instance()->Update();
		if (Input::Instance()->GetKeyDown() == SDLK_ESCAPE || Input::Instance()->IsWindowClosed())
		{
			isGameRunning = false;
		}

		//button.Update();
		//button.Render();

		checkbox.Update();
		checkbox.Render();
		
		//slider.HandleEvent(Input::Instance()->events);
		//slider.Render();


		//toggleButton.HandleEvent(Input::Instance()->events);
		//toggleButton.Render();

		//modalWindow.HandleEvent(Input::Instance()->events);
		//modalWindow.Render();

		Screen::Instance()->Present();
	}

	Screen::Instance()->Shutdown();
	return 0;
}