#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL; 		//Loading success flag	
SDL_Surface* gScreenSurface = NULL;	//The surface contained by the window
SDL_Surface* gHelloWorld = NULL;	//The image we will load and show on the screen

bool init() {
	bool success = true; 					//Initialization flag
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {		//Initialize SDL
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gWindow == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			gScreenSurface = SDL_GetWindowSurface(gWindow); //Get window surface
		}
	}
	return success;
}

bool loadMedia() {
	bool success = true; 								//Loading success flag
	gHelloWorld = IMG_Load("./res/gradientbg.jpg");	//load splash image
	if(gHelloWorld == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

void close() {
	SDL_FreeSurface( gHelloWorld );			//Deallocate surface
	gHelloWorld = NULL;
	SDL_DestroyWindow( gWindow );			//Destroy window
	gWindow = NULL;
	SDL_Quit();								//Quit SDL subsystems
}

int main(int argc, char* args[]) {
	if(!init()) { 							//Start up SDL and create window
		printf("Failed to initialize!\n");
	}
	else {
		if(!loadMedia()) { 					//Load media
			printf("Failed to load media!\n");
		}
		else {
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL); //Apply the image
			SDL_UpdateWindowSurface(gWindow);							//Update the surface
			SDL_Delay(2000);
		}
	}
	close();															//Free resources and close SDL
	return 0;
}