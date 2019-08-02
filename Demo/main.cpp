
#include <iostream>
#include <Mark/Window.h>
#include <Mark/ResourceManager.h>
#include <Mark/Debug.h>


int main()
{

	Mark::Window* wnd = new Mark::Window(1920, 1080, "Mark 0.1", 60);

	void (Mark::Window::*closeWnd)() = &Mark::Window::Close;
	wnd->AddWindowEvent(sf::Event::Closed, closeWnd, sf::Keyboard::Unknown);

	Mark::ResourceManager mgr = Mark::ResourceManager::Instance();
	sf::Texture bg = mgr.GetTexture("bg.jpg");
	sf::Sprite s(bg);

	while (wnd->IsOpen())
	{
		wnd->HandleWindowEvents();

		wnd->Clear();

		wnd->Draw(s);

		wnd->Display();
	}

	delete wnd;
	wnd = nullptr;

	return 0;
}