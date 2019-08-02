#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <vector>

namespace Mark
{

	class Window;

	struct WEventDetails
	{
		int eventKey;
		void (Window::*callback)();

		WEventDetails(int key, void (Window::*func)())
		{
			eventKey = key;
			callback = func;
		}
		WEventDetails()
		{
			eventKey = -1;
			callback = nullptr;
		}
	};

	class Window
	{
	public:
		Window(int width, int height, std::string windowName, int framerateLimit);
		~Window();

		void HandleWindowEvents();
		void Clear();
		void Draw(const sf::Drawable& target);
		void Draw(const sf::Vertex* vertices, size_t vertexCount, sf::PrimitiveType type);
		void Display();
		//Use only for window events!
		//Events of other objects must handled by themself
		//For example: player->HandleEvents();
		bool AddWindowEvent(const sf::Event::EventType& type, void (Window::*callback)(),int key);

		bool IsOpen() const;
		void Close();

	private:
		sf::RenderWindow* m_wnd;
		std::unordered_map<sf::Event::EventType, std::vector<WEventDetails*>>* m_wndEvents;
	};
};


