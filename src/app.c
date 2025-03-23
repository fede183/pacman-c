#include <stdbool.h>  
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#include "text_box.c"
#include "texture_to_load.c"
#include "rectagle.c"
#include "classes/app.h"
#include "classes/config.h"
#include "game.c"

App* app;
Game* game;
bool quit;

SDL_Color SDLColors[8] = {BLUE_COLOR, VIOLET_COLOR, RED_COLOR, GREEN_COLOR, YELLOW_COLOR, LIGHT_BLUE_COLOR, ORANGE_COLOR, MEDIUM_BLUE_COLOR};
int rendererFlags = SDL_RENDERER_ACCELERATED;
int windowFlags = 0;

void cleanup();
void init_SDL();
void handle_input(SDL_Keycode);
void do_input();
void prepare_scene();
void present_scene();
void draw_game_state();
void draw_piece();
void draw_occupied_points();
void draw_point();

void init_SDL(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	if (TTF_Init() < 0) {
		printf("Couldn't initialize TTF: %s\n", SDL_GetError());
		exit(1);
	}

	app->window = SDL_CreateWindow("Pacman C", 
                                       0,
                                       0,
                                       DISPLAY_WIDTH, DISPLAY_HEIGTH, windowFlags);

	if (!app->window)
	{
		printf("Failed to open %d x %d window: %s\n", DISPLAY_WIDTH, DISPLAY_HEIGTH, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app->renderer = SDL_CreateRenderer(app->window, -1, rendererFlags);

	if (!app->renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}

	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 512) == -1) {
		printf("Failed to create audio: %s\n", SDL_GetError());
		exit(1);
	}

	app->music = Mix_LoadMUS(BEGINNING_MUSIC_FILE);

	if (!app->music)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}

	if (Mix_PlayMusic(app->music, -1) == -1) {
		printf("Failed to play music: %s\n", SDL_GetError());
		exit(1);
        }

	app->score = init_text(DISPLAY_SCORE_WIGTH, DISPLAY_SCORE_HEIGTH, DISPLAY_SCORE_X, DISPLAY_SCORE_Y);

	app->pacman = init_texture(10.0, 10.0, 10.0, 10.0);

	game = create_game();

	quit = false;
}

bool is_quit() {
	return quit;
}

void cleanup() {
	if (app->score) {
		free(app->score);
	}
	if (app->renderer) {
		SDL_DestroyRenderer(app->renderer);
	}
	if (app->window) {
		SDL_DestroyWindow(app->window);
	}
	if (app->game_over_message) {
		free(app->game_over_message);
	}
	if (app->game_over_renderer) {
		SDL_DestroyRenderer(app->game_over_renderer);
	}
	if (app->game_over_window) {
		SDL_DestroyWindow(app->game_over_window);
	}
	if (app->music) {
		Mix_FreeMusic(app->music);
    		Mix_CloseAudio();
	}

	clean_texture(app->pacman);
	clean_game(game);
	free(app);
	TTF_Quit();
	SDL_Quit();
	quit = true;
}

void prepare_scene(void)
{
	SDL_Color background_color = GREY_COLOR;
	SDL_SetRenderDrawColor(app->renderer, background_color.r, background_color.g, background_color.b, background_color.a);
	SDL_RenderClear(app->renderer);
}

void present_scene(void)
{
	show_texture(app->pacman, app->renderer, "../images/pacman_openmounth.bmp");
	SDL_RenderPresent(app->renderer);
}

void draw_game_state() {

}

void handle_input(SDL_Keycode code) {
	if (code == SDLK_ESCAPE || code == SDLK_q) {
		cleanup();
	}
}

void do_input(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				cleanup();
				break;
			case SDL_KEYDOWN:
				handle_input(event.key.keysym.sym);
				break;
			default:
				break;
		}
	}
}

void cycle() {
	SDL_Delay(100);
}

// Game Over Window
bool check_game_over() {
	return false;
}

void init_game_over() {
	app->game_over_window = SDL_CreateWindow("Game Over", 
                                       0,
                                       0,
                                       GAME_OVER_DISPLAY_WIDTH, GAME_OVER_DISPLAY_HEIGTH, windowFlags);

	if (!app->game_over_window)
	{
		printf("Failed to open %d x %d window: %s\n", GAME_OVER_DISPLAY_WIDTH, GAME_OVER_DISPLAY_HEIGTH, SDL_GetError());
		exit(1);
	}

	app->game_over_renderer = SDL_CreateRenderer(app->game_over_window, -1, rendererFlags);

	if (!app->game_over_renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}

	app->game_over_message = init_text(DISPLAY_GAME_OVER_MESSAGE_WIGTH, DISPLAY_GAME_OVER_MESSAGE_HEIGTH, DISPLAY_GAME_OVER_MESSAGE_X, DISPLAY_GAME_OVER_MESSAGE_Y);
}

void prepare_game_over_scene(void)
{
	SDL_Color background_color = RED_COLOR;
	SDL_SetRenderDrawColor(app->game_over_renderer, background_color.r, background_color.g, background_color.b, background_color.a);
	SDL_RenderClear(app->game_over_renderer);
}

void present_game_over_scene(void)
{
	char* game_over_text = "Game Over! Press q or Esc to quit";
	show_text(app->game_over_message, app->game_over_renderer, game_over_text);

	SDL_RenderPresent(app->game_over_renderer);
}

void handle_input_game_over(SDL_Keycode code) {
	if (code == SDLK_ESCAPE || code == SDLK_q) {
		cleanup();
	}
}

void do_input_game_over(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				cleanup();
				break;
			case SDL_KEYDOWN:
				handle_input_game_over(event.key.keysym.sym);
				break;
			default:
				break;
		}
	}
}
