#include <SDL.h>
#include "parallax.h"
//#include "iostream_app.h"
#include <iostream>
#include <memory>

int SDL_main(int argc, char *argv[])
{
	std::unique_ptr<SDL_App> a(new ParallaxDemo); int r = a->Execute();
	std::cout << "Exitting!" << std::endl; std::cin.get();
	return r;
}