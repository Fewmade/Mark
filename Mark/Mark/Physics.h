#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace Mark
{
	class AABB
	{
	public:
		AABB(int width, int height);
		~AABB();

		bool IsCollide(const AABB& box);
		void Resize(int width, int height);
		void SetPosition(sf::Vector2f position);

		const sf::Vector2f& GetPosition() const;
		const sf::Vector2f& GetSize() const;

	private:
		sf::RectangleShape m_AABB;
	};
};
