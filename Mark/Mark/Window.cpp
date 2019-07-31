#include "stdafx.h"
#include "Window.h"


Mark::Window::Window(int width, int height, std::string windowName, int framerateLimit)
{
	m_wnd = new sf::RenderWindow(sf::VideoMode(width, height), windowName);
	m_wnd->setFramerateLimit(framerateLimit);

	m_wndEvents = new std::unordered_map<sf::Event::EventType, std::vector<WEventDetails*>>();
}


Mark::Window::~Window()
{
	delete m_wndEvents;
	m_wndEvents = nullptr;
	delete m_wnd;
	m_wnd = nullptr;



}

void Mark::Window::HandleWindowEvents()
{
	
	sf::Event e;
	while (m_wnd->pollEvent(e))
	{
		if (m_wndEvents->find(e.type) != m_wndEvents->end())
		{
			for (auto& i : m_wndEvents->at(e.type))
			{
				if (i->eventKey >= 0)
				{
					if (e.key.code == i->eventKey)
					{
						(this->*i->callback)();
					}
				}
				else
				{
					(this->*i->callback)();
				}
			}
		}
	}
	
	
}

bool Mark::Window::AddWindowEvent(const sf::Event::EventType& type, void (Window::*func)(),int key)
{

	if (m_wndEvents->find(type) != m_wndEvents->end())
	{
		m_wndEvents->at(type).push_back(new Mark::WEventDetails(key, func));
		
	}
	else
	{
		Mark::WEventDetails* details = new Mark::WEventDetails(key, func);
		std::vector<WEventDetails*> v;
		v.push_back(details);
		m_wndEvents->emplace(type, v);
	}

	return true;
}

bool Mark::Window::IsOpen() const
{
	return m_wnd->isOpen();
}

void Mark::Window::Close()
{
	m_wnd->close();
}
