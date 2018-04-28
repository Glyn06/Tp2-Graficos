#include <SDL.h>
#include <iostream>

const int SCREEN_HEIGTH = 800;
const int SCREEN_WIDTH = 640;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Rect rectangle;
SDL_Event eventManager;
bool gameOver = false;



int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);

	//init rectangle
	rectangle.x = 100;
	rectangle.y = 100;
	rectangle.h = 50;
	rectangle.w = 25;

	//create window
	window = SDL_CreateWindow("Programacion de graficos Tp2", 100, 100, SCREEN_WIDTH, SCREEN_HEIGTH, 0);
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


	while (!gameOver)
	{
		while (SDL_PollEvent(&eventManager))
		{
			if (eventManager.type == SDL_QUIT || eventManager.key.keysym.sym == SDLK_ESCAPE)
				gameOver = true;

			if (eventManager.key.keysym.sym == SDLK_RIGHT)
				rectangle.x++;
			if (eventManager.key.keysym.sym == SDLK_LEFT)
				rectangle.x--;
			if (eventManager.key.keysym.sym == SDLK_UP)
				rectangle.y--;
			if (eventManager.key.keysym.sym == SDLK_DOWN)
				rectangle.y++;
		}



		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

		SDL_RenderFillRect(renderer, &rectangle);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		SDL_RenderPresent(renderer);

	}

	return 0;
}

//Tuto usado: http://headerphile.com/sdl2/sdl2-part-3-drawing-rectangles/