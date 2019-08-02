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

		void Update(float elapsed);

		int GetFPS() const;

	private:
		Window* m_wnd;
		
		sf::Clock m_clock;
		float m_timer;
		unsigned char m_prevFPS;
		unsigned char m_fps;
	};
}

