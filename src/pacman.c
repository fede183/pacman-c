#include "classes/pacman.h"

Pacman* create_pacman() {
	Pacman* pacman = (Pacman*) malloc(sizeof(Pacman));

	pacman->position_x = 10;
	pacman->position_y = 10;

	return pacman;
}

