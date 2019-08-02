
#include <iostream>
#include <Mark/Window.h>
#include <Mark/ResourceManager.h>
#include <Mark/Debug.h>
#include <Mark/Time.h>
#include <Mark/Animation.h>


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

	Mark::Animation anim(knight, 1, 4, sf::Vector2i(50,37));
	anim.GetSprite().setScale(sf::Vector2f(4.f, 4.f));

	while (wnd->IsOpen())
	{
		wnd->HandleWindowEvents();

		anim.Update(Mark::Time::Instance().GetElapsedTime());

		wnd->Clear();

		wnd->Draw(s);
		wnd->Draw(anim.GetSprite());

		wnd->Display();
	}

	delete wnd;
	wnd = nullptr;

	return 0;
}