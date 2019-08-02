#pragma once

#include <SFML/Graphics.hpp>


namespace Mark
{
	struct Spritesheet
	{
		sf::Sprite sprite;
		
		//Less than 256 frames!
		unsigned char rows;
		unsigned char cols;
		
		sf::Vector2i spriteSize;
		sf::Vector2i currentFrame;

		Spritesheet(sf::Texture& t, unsigned char _rows, unsigned char _cols, sf::Vector2i _spriteSize)
		{
			sprite.setTexture(t);
			rows = _rows;
			cols = _cols;
			spriteSize = _spriteSize;

			currentFrame.x = 0;
			currentFrame.y = 0;
		}
		Spritesheet()
		{
			rows = 0;
			cols = 0;
			currentFrame.x = 0;
			currentFrame.y = 0;
		}
	};

	class Animation
	{
	public:
		Animation(const Spritesheet& spritesheet, float animDelay = 0.2f);
		Animation(sf::Texture& texture, unsigned char sheetRows, unsigned char sheetCols, sf::Vector2i spriteSize, bool playOnStart = true, float animDelay = 0.2f);
		~Animation();


		void Play();
		void Stop();
		void Reset();
		void Update(float elapsed);

		void SetAnimDelay(float delay);

		sf::Sprite& GetSprite();

	private:
		Spritesheet m_spritesheet;
		float m_animationDelay;
		bool m_isPlayed;

		float m_delay;
	};
};



