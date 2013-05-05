#ifndef ENTITY_H
#define ENTITY_H

#include "SDL_surface.h"
#include "2DMath.h"

struct Entity 
{
	SDL_Surface * model;
	Vector pos, dim, vel, accel; // dim = dimension of model
	bool RAII;
	Entity() : model(nullptr),RAII(false) 
	{
		pos = dim = vel = accel = Vector( 0 , 0 );
	}
	virtual ~Entity() 
	{
		if ( RAII ) 
			SDL_FreeSurface(model);
	}
	
	math::Rectangle Rect() { return math::Rectangle( pos, dim ); }

	virtual bool Init(SDL_Surface* s)
	{
		model = s;
		return true;
	}
	virtual bool Init(const std::string& s)
	{
		model = Surface::PngLoad((char*)s.c_str());
		RAII = true;
		return true;
	}
	virtual void Logic(float dt)
	{
		pos += vel*dt + (1/2.f)*accel*dt*dt;
		vel += accel*dt;
	}
};

#endif