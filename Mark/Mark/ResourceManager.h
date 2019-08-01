#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>

namespace Mark
{

	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();

		//Singleton
		static ResourceManager& Instance()
		{
			static ResourceManager obj;
			return obj;
		}

		//Load maps in memory
		void Init(std::string resourceFolder);
		//Unload maps from memory
		void Unload();

		//Getting resources
		sf::Texture& GetTexture(std::string name);
		sf::Image& GetImage(std::string name);
		sf::Font& GetFont(std::string name);
		sf::Shader& GetShader(std::string ertexName, std::string fragmentName);
		sf::Music& GetMusic(std::string name);

		//Unload resources
		bool UnloadTexture(std::string name);
		bool UnloadImage(std::string name);
		bool UnloadFont(std::string name);
		bool UnloadShader(std::string name);
		bool UnloadMusic(std::string name);

	private:
		std::map<std::string, sf::Texture*>* m_loadedTextures;
		std::map<std::string, sf::Image*>* m_loadedImages;
		std::map<std::string, sf::Font*>* m_loadedFonts;
		std::map<std::string, sf::Shader*>* m_loadedShaders;
		std::map<std::string, sf::Music*>* m_loadedMusic;


		std::string m_resourceFolder;
	};
};



