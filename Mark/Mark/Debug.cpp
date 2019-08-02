#include "stdafx.h"
#include "Debug.h"


Mark::DebugManager::DebugManager(Mark::Window& wnd)
{
	m_wnd = &wnd;
}

Mark::DebugManager::~DebugManager()
{
	//DO NOT DELETE m_wnd!!!!!!
}

void Mark::DebugManager::AddLine(const sf::Vector2f& from, const sf::Vector2f& to, sf::Color color)
{
	sf::Vertex line[] =
	{
		sf::Vertex(from),
		sf::Vertex(to)
	};
	line[0].color = color;
	line[1].color = color;

	m_wnd->Draw(line, 2, sf::Lines);
}

void Mark::DebugManager::AddCircle(const sf::Vector2f& center, float radius, sf::Color color)
{
	sf::CircleShape circle(radius);
	circle.setPosition(center);
	circle.setFillColor(color);

	m_wnd->Draw(circle);
}

void Mark::DebugManager::AddAABB(const sf::Vector2f& minCoords, const sf::Vector2f& maxCoords, sf::Color color)
{
	sf::RectangleShape box(sf::Vector2f(abs(maxCoords.x) - abs(minCoords.x), abs(maxCoords.y) - abs(minCoords.y)));
	box.setOutlineThickness(2.f);
	box.setOutlineColor(color);
	box.setFillColor(sf::Color::Transparent);
	box.setPosition(sf::Vector2f((maxCoords.x + minCoords.x) / 2, (maxCoords.y + minCoords.y) / 2));

	m_wnd->Draw(box);
}
