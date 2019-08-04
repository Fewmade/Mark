
#include <iostream>
#include <Mark/Window.h>
#include <Mark/ResourceManager.h>
#include <Mark/Debug.h>
#include <Mark/Time.h>
#include <Mark/Animation.h>
#include <Physics.h>

int main()
{

	Mark::Window* wnd = new Mark::Window(1920, 1080, "Mark 0.1", 60);

	void (Mark::Window::*closeWnd)() = &Mark::Window::Close;
	wnd->AddWindowEvent(sf::Event::Closed, closeWnd, sf::Keyboard::Unknown);

	Mark::ResourceManager mgr = Mark::ResourceManager::Instance();
	sf::Texture bg = mgr.GetTexture("bg.jpg");
	sf::Texture knight = mgr.GetTexture("knight.png");
	sf::Sprite s(bg);

	Mark::DebugManager debug(*wnd);

	Mark::AABB aabb(100, 50);
	aabb.SetPosition(sf::Vector2f(0.f, 0.f));
	Mark::AABB _aabb(100, 50);
	_aabb.SetPosition(sf::Vector2f(100.f, 0.f));

	if (aabb.IsCollide(_aabb))
	{
		std::cout << "Collide!";
	}

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