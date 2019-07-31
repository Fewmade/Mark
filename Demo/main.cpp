
#include <iostream>
#include <Mark/Window.h>


int main()
{

	Mark::Window* wnd = new Mark::Window(800, 600, "Mark 0.1", 60);

	void (Mark::Window::*closeWnd)() = &Mark::Window::Close;
	wnd->AddWindowEvent(sf::Event::Closed, closeWnd, sf::Keyboard::Unknown);

	while (wnd->IsOpen())
	{
		wnd->HandleWindowEvents();
	}


	
	delete wnd;
	wnd = nullptr;

	return 0;
}