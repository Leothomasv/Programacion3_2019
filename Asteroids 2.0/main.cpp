#include <iostream>

#include <SDL.h>

int main(int argc, char *argv[]) {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "HUBO UN ERROR" << SDL_GetError() << std::endl;

	}
	return EXIT_SUCCESS;
}