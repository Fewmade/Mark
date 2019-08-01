#pragma once

#include <SFML/Graphics.hpp>


namespace Mark
{
	class Time
	{
		public:
			Time();
			~Time();

			static Time& Instance()
			{
				static Time obj;
				return obj;
			}

			float Restart();
			float GetElapsedTime() const;

		private:
			sf::Clock m_clock;
			float m_elapsed;
	};
};


