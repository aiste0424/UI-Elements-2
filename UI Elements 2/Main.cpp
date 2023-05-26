#include <SDL.h>
#include <iostream>

#include "Screen.h"
#include "Input.h"
#include "Checkbox.h"
#include "ProgressBar.h"
#include "Button.h"
#include "ModalWindow.h"
#include "Slider.h"
#include "ToggleButton.h"

int main(int argc, char* argv[])
{
	bool isGameRunning = true;
	

	if (!Screen::Instance()->Initialize("Test", { 1280, 720 }))
	{
		std::cout << "Screen failed to initialize" << std::endl;
		return 0;
	}

	Checkbox checkbox;
	Button button;
	ProgressBar progressBar;
	ModalWindow modalWindow;
	Slider slider;
	ToggleButton toggleButton;

	progressBar.SetValue(10);
	int progressBarValue = 10;

	while (isGameRunning)
	{
		Screen::Instance()->Clear();
		Input::Instance()->Update();
		if (Input::Instance()->GetKeyDown() == SDLK_ESCAPE || Input::Instance()->IsWindowClosed())
		{
			isGameRunning = false;
		}

		button.Render();

		checkbox.Render();
		checkbox.Update();

		slider.HandleEvent(Input::Instance()->events);
		slider.Render();

		if (button.Update() == true)
		{
			progressBarValue += 10;
			progressBar.SetValue(progressBarValue);
		}
		
		progressBar.Render();

		toggleButton.HandleEvent(Input::Instance()->events);
		toggleButton.Render();

		if (Input::Instance()->GetKeyDown() == SDLK_2)
		{
			modalWindow.SetOpen();
		}

		modalWindow.HandleEvent(Input::Instance()->events);
		modalWindow.Render();

		Screen::Instance()->Present();
	}

	Screen::Instance()->Shutdown();
	return 0;
}