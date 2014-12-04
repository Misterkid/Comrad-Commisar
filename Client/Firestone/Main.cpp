/*  */

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

//Screen settings
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

bool init();

bool loadAssets();

void close();

//Load individual image for now
SDL_Surface* loadSurface( std::string path );

//The window used to render to cc = Comrade Commissar
SDL_Window* ccWindow = NULL;

//Surface of the window
SDL_Surface* ccScreenSurface = NULL;

//The test image to load on screen
SDL_Surface* ComradeCommissar = NULL;

bool init()
{
	//flag
	bool success = true;

	//init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		ccWindow = SDL_CreateWindow("Commrade Commissar", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (ccWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//init png Loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not be initialized! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			else
			{
				//get window surface
				ccScreenSurface = SDL_GetWindowSurface(ccWindow);
			}
		}
	}

	return success;
}

bool loadAssets()
{
	//flag
	bool success = true;

	//Load png surface
	ComradeCommissar = loadSurface("cc.png");
	if (ComradeCommissar == NULL)
	{
		printf("Failed to load png image!\n");
		success = false;
	}

	return success;
}

void close()
{
	// free loaded image
	SDL_FreeSurface(ComradeCommissar);
	ComradeCommissar = NULL;

	// destroy window
	SDL_DestroyWindow(ccWindow);
	ccWindow = NULL;

	//quit sdl subsystem
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface( std::string path)
{
	//the fial optemized image
	SDL_Surface* optemizedSurface = NULL;

	//load image from path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		// convert surface to screen format
		optemizedSurface = SDL_ConvertSurface( loadedSurface, ccScreenSurface->format, NULL);
		if (optemizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optemizedSurface;
}

int main(int argc, char* args[])
{
	// start sdl and create window
	if (!init())
	{
		printf("failed to start SDL");
	}
	else 
	{
		//load media
		if (!loadAssets())
		{
			printf("failed to load media! \n");
		}
		else
		{
			bool quit = false;

			SDL_Event e;

			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}


				SDL_BlitSurface(ComradeCommissar, NULL, ccScreenSurface, NULL);

				SDL_UpdateWindowSurface(ccWindow);
			}
		}
	}

	close();

	return 0;
}