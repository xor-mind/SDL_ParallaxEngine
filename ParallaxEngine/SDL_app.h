#ifndef SDL_APP_H
#define SDL_APP_H

#include "App.h"
#include "SDL_surface.h"
#include "SDL_event.h"

#include <SDL.h>
#include <vector>
#include <algorithm>
#include <functional>

class SDL_App : public App, public Event
{
public:
	SDL_App() {
	}
	virtual ~SDL_App() {}
	SDL_Surface * display;
protected:
	virtual bool Init() override
	{
		if(SDL_Init(SDL_INIT_EVERYTHING) < 0) 
		{
			return false;
		}
 		if( (display = SDL_SetVideoMode( 600, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) 
		{
			return false;
		}
		return true;
	}
		
	void GameLoop() override
	{
		SDL_Event Event;
 
		while(running) 
		{
			while(SDL_PollEvent(&Event)) {
				OnEvent(&Event);
			}
 
			Logic();
			Render();
		}
	}

	void Event(SDL_Event* event) 
	{
		Event::OnEvent(event);
	}
 
	void Logic() override  
	{
	}
 
	void Render() override
	{
		SDL_Flip(display);
	}
 
	void Cleanup() override
	{
		SDL_Quit();
	}

	void Exit() override {
		running = false;
	}
};

#endif