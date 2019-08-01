#include "stdafx.h"
#include "ResourceManager.h"

Mark::ResourceManager::ResourceManager()
{
	
}


Mark::ResourceManager::~ResourceManager()
{

}


void Mark::ResourceManager::Init(std::string resourceFolder)
{
	m_loadedTextures = nullptr;
	m_loadedImages = nullptr;
	m_loadedFonts = nullptr;
	m_loadedShaders = nullptr;
	m_loadedMusic = nullptr;

	m_resourceFolder = resourceFolder;
}

void Mark::ResourceManager::Unload()
{
	m_loadedMusic->clear();
	m_loadedShaders->clear();
	m_loadedFonts->clear();
	m_loadedImages->clear();
	m_loadedTextures->clear();

	delete m_loadedMusic;
	delete m_loadedShaders;
	delete m_loadedFonts;
	delete m_loadedImages;
	delete m_loadedTextures;

	m_loadedTextures = nullptr;
	m_loadedImages = nullptr;
	m_loadedFonts = nullptr;
	m_loadedShaders = nullptr;
	m_loadedMusic = nullptr;
}

sf::Texture& Mark::ResourceManager::GetTexture(std::string name)
{
	//Allocate if doesnt exist
	if (m_loadedTextures == nullptr)
		m_loadedTextures = new std::map<std::string, sf::Texture*>();

	
	if (m_loadedTextures->find(name) == m_loadedTextures->end())
	{
		sf::Texture* t = new sf::Texture();
		if (!t->loadFromFile(m_resourceFolder + name))
		{
			//Throw exception
		}

		m_loadedTextures->emplace(name, t);
	}
	
	
	return *m_loadedTextures->at(name);
}
sf::Image& Mark::ResourceManager::GetImage(std::string name)
{
	//Allocate if doesnt exist
	if (m_loadedImages == nullptr)
		m_loadedImages = new std::map<std::string, sf::Image*>();


	if (m_loadedImages->find(name) == m_loadedImages->end())
	{
		sf::Image* t = new sf::Image();
		if (!t->loadFromFile(m_resourceFolder + name))
		{
			//Throw exception
		}

		m_loadedImages->emplace(name, t);
	}


	return *m_loadedImages->at(name);
}
sf::Font& Mark::ResourceManager::GetFont(std::string name)
{
	//Allocate if doesnt exist
	if (m_loadedFonts == nullptr)
		m_loadedFonts = new std::map<std::string, sf::Font*>();


	if (m_loadedFonts->find(name) == m_loadedFonts->end())
	{
		sf::Font* t = new sf::Font();
		if (!t->loadFromFile(m_resourceFolder + name))
		{
			//Throw exception
		}

		m_loadedFonts->emplace(name, t);
	}


	return *m_loadedFonts->at(name);
}
sf::Shader& Mark::ResourceManager::GetShader(std::string vertexName, std::string fragmentName)
{
	//Allocate if doesnt exist
	if (m_loadedShaders == nullptr)
		m_loadedShaders = new std::map<std::string, sf::Shader*>();


	if (m_loadedShaders->find(vertexName) == m_loadedShaders->end())
	{
		sf::Shader* t = new sf::Shader();
		if (!t->loadFromFile(m_resourceFolder + vertexName, m_resourceFolder + fragmentName))
		{
			//Throw exception
		}

		m_loadedShaders->emplace(vertexName, t);
	}


	return *m_loadedShaders->at(vertexName);
}
sf::Music& Mark::ResourceManager::GetMusic(std::string name)
{
	//Allocate if doesnt exist
	if (m_loadedMusic == nullptr)
		m_loadedMusic = new std::map<std::string, sf::Music*>();


	if (m_loadedMusic->find(name) == m_loadedMusic->end())
	{
		sf::Music* t = new sf::Music();
		if (!t->openFromFile(m_resourceFolder + name))
		{
			//Throw exception
		}

		m_loadedMusic->emplace(name, t);
	}


	return *m_loadedMusic->at(name);
}

bool Mark::ResourceManager::UnloadTexture(std::string name)
{
	if (m_loadedTextures->find(name) == m_loadedTextures->end())
	{
		return false;
	}

	sf::Texture* t = m_loadedTextures->at(name);
	delete t;
	t = nullptr;

	m_loadedTextures->erase(name);
	return true;
}
bool Mark::ResourceManager::UnloadImage(std::string name)
{
	if (m_loadedImages->find(name) == m_loadedImages->end())
	{
		return false;
	}

	sf::Image* t = m_loadedImages->at(name);
	delete t;
	t = nullptr;

	m_loadedImages->erase(name);
	return true;
}
bool Mark::ResourceManager::UnloadFont(std::string name)
{
	if (m_loadedFonts->find(name) == m_loadedFonts->end())
	{
		return false;
	}

	sf::Font* t = m_loadedFonts->at(name);
	delete t;
	t = nullptr;

	m_loadedFonts->erase(name);
	return true;
}
bool Mark::ResourceManager::UnloadShader(std::string name)
{
	if (m_loadedShaders->find(name) == m_loadedShaders->end())
	{
		return false;
	}

	sf::Shader* t = m_loadedShaders->at(name);
	delete t;
	t = nullptr;

	m_loadedShaders->erase(name);
	return true;
}
bool Mark::ResourceManager::UnloadMusic(std::string name)
{
	if (m_loadedMusic->find(name) == m_loadedMusic->end())
	{
		return false;
	}

	sf::Music* t = m_loadedMusic->at(name);
	delete t;
	t = nullptr;

	m_loadedMusic->erase(name);
	return true;
}
