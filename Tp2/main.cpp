#include <SDL.h>
#include <SDL_image.h>
#ifdef DEBUG
	#include<vld.h>
#endif // DEBUG
#include <iostream>

const int SCREEN_HEIGTH = 800;
const int SCREEN_WIDTH = 640;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* img;
SDL_Rect rectangle;
SDL_Event eventManager;

bool gameOver = false;



int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVERYTHING);

	//init rectangle
	rectangle.x = 100;
	rectangle.y = 100;
	rectangle.h = 100;
	rectangle.w = 100;

	//create window
	window = SDL_CreateWindow("Programacion de graficos Tp2", 100, 100, SCREEN_WIDTH, SCREEN_HEIGTH, 0);
	if (window == nullptr)
		std::cout << "Failed to create window : " << SDL_GetError();

	//create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
		std::cout << "Failed to create renderer : " << SDL_GetError();

	//set renderer size to window size
	SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGTH);

	//set color to red
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_Surface* sur = IMG_Load("SadFace.png");
	if (sur == NULL)
		std::cout << "Fallo la imagen ";

	img = SDL_CreateTextureFromSurface(renderer, sur);
	SDL_FreeSurface(sur);


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

		SDL_RenderCopy(renderer, img, NULL, &rectangle);

		SDL_RenderPresent(renderer);

		SDL_Delay(16);

	}

	return 0;
}