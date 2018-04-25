#include <SDL.h>
#include <iostream>

const int SCREEN_HEIGTH = 800;
const int SCREEN_WIDTH = 640;

SDL_Window* window;
SDL_Renderer* renderer;



int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);
	
	//create window
	window = SDL_CreateWindow("Programacion de graficos II Tp2",0,0,SCREEN_WIDTH,SCREEN_HEIGTH,0);
	if (window == nullptr)
		std::cout << "Failed to create window : " << SDL_GetError();

	//create renderer
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == nullptr)
		std::cout << "Failed to create renderer : " << SDL_GetError();
	
	//set renderer size to window size
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGTH);

	//set color to red
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	//render stuff
	SDL_RenderClear(renderer); //setwindowcolor to red
	SDL_RenderPresent(renderer); // present the changes above

	//Delay pa' que no cierra (Ah rre escribia todo en ingles re bonito y despues saltaba en español)
	SDL_Delay(2000);

	return 0;
}

//Tuto usado: http://headerphile.com/sdl2/sdl2-part-3-drawing-rectangles/