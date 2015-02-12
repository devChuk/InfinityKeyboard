#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

//Texture wrapper class
class LTexture {
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image at specified path
	bool loadFromFile( std::string path );
	
	//Creates image from font string
	bool loadFromRenderedText( std::string textureText, SDL_Color textColor );

	//Deallocates texture
	void free();

	//Set color modulation
	void setColor( Uint8 red, Uint8 green, Uint8 blue );

	//Set blending
	void setBlendMode( SDL_BlendMode blending );

	//Set alpha modulation
	void setAlpha( Uint8 alpha );
	
	//Renders texture at given point
	void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};

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
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL); 	//Apply the image
			SDL_UpdateWindowSurface(gWindow);							//Update the surface
			SDL_Delay(2000);
		}
	}
	close();															//Free resources and close SDL
	return 0;
}