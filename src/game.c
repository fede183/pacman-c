#include "classes/game.h"
#include "pacman.c"

Game* create_game() {
	Game* game = (Game*) malloc(sizeof(Game));

	game->pacman = create_pacman();

	return game;
}

void clean_game(Game* game) {
	free(game->pacman);
	free(game);
}
