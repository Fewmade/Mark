#pragma once

#include <SFML/Graphics.hpp>
#include <Mark/Window.h>

namespace Mark
{
	class DebugManager
	{
	public:

		DebugManager(Window& wnd);
		~DebugManager();


		void AddLine(const sf::Vector2f& from, const sf::Vector2f& to, sf::Color color);
		void AddCircle(const sf::Vector2f& center, float radius, sf::Color color);
		void AddAABB(const sf::Vector2f& minCoords, const sf::Vector2f& maxCoords, sf::Color color);


	private:
		Window* m_wnd;
	};
}

