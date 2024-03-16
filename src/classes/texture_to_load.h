#include <SDL2/SDL.h>

#ifndef TEXTURE_TO_LOAD_H
#define TEXTURE_TO_LOAD_H

typedef struct {
	SDL_Surface* surface;
	SDL_Texture* texture;
	SDL_Rect rect;
} TextureToLoad;

#endif //TEXTURE_TO_LOAD_H
