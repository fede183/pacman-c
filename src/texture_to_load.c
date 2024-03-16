#include "classes/texture_to_load.h"

void _clean_texture_sdl(TextureToLoad* texture_to_load) {
	if (texture_to_load->surface) {
		SDL_FreeSurface(texture_to_load->surface);
	}
	if (texture_to_load->texture) {
		SDL_DestroyTexture(texture_to_load->texture);
	}
}

void clean_texture(TextureToLoad* texture_to_load) {
	_clean_texture_sdl(texture_to_load);
	free(texture_to_load);
}

TextureToLoad* init_texture(float w, float h, float x, float y) {
	TextureToLoad* texture_to_load = (TextureToLoad*) malloc(sizeof(TextureToLoad));

	SDL_Rect rect; 
	rect.x = x; 
	rect.y = y;
	rect.w = w;
	rect.h = h;

	texture_to_load->rect = rect;

	return texture_to_load;
}

void show_texture(TextureToLoad* texture_to_load, SDL_Renderer* renderer, char* texture_file) {
	SDL_Color Black = {0, 0, 0};

	texture_to_load->surface = SDL_LoadBMP(texture_file);

	if (texture_to_load->surface == NULL) {
		printf("Surface load error: %s\n", SDL_GetError());
		exit(0);
	}

	texture_to_load->texture = SDL_CreateTextureFromSurface(renderer, texture_to_load->surface);

	if (texture_to_load->texture == NULL) {
		printf("Texture load error: %s\n", SDL_GetError());
		exit(0);
	}
	if (SDL_QueryTexture(texture_to_load->texture, NULL, NULL, &texture_to_load->rect.w, &texture_to_load->rect.h) < 0) {
		printf("Query texture error: %s\n", SDL_GetError());
		exit(0);
	}
	if (SDL_RenderCopy(renderer, texture_to_load->texture, NULL, &texture_to_load->rect) < 0) {
		printf("Render copy error: %s\n", SDL_GetError());
		exit(0);
	}

	_clean_texture_sdl(texture_to_load);
}

