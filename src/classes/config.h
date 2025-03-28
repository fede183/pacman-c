// Square base sizes
#define SQUARE_SIZE 20 

#define VISIBLE_VERTICAL_BOARD 50
#define HORIZONTAL_BOARD 50
#define HEADER 1
#define FOOTER 1
#define VISIBLE_BOARD_X 1

#define HORIZONTAL_SIZE (HORIZONTAL_BOARD + VISIBLE_BOARD_X + 2)
#define VERTICAL_SIZE (VISIBLE_VERTICAL_BOARD + HEADER + FOOTER)

#define SCORE_HORIZONTAL 5
#define SCORE_VERTICAL 2
#define SCORE_X 5
#define SCORE_Y 7

// Display sizes
#define DISPLAY_WIDTH SQUARE_SIZE*HORIZONTAL_SIZE
#define DISPLAY_HEIGTH SQUARE_SIZE*VERTICAL_SIZE

#define DISPLAY_BOARD_WIDTH SQUARE_SIZE*HORIZONTAL_BOARD
#define DISPLAY_BOARD_HEIGTH SQUARE_SIZE*VISIBLE_VERTICAL_BOARD
#define DISPLAY_BOARD_X SQUARE_SIZE*VISIBLE_BOARD_X
#define DISPLAY_BOARD_Y SQUARE_SIZE*HEADER

#define DISPLAY_LOST_MESSAGE_WIDTH 500
#define DISPLAY_LOST_MESSAGE_HEIGTH 200

#define DISPLAY_SCORE_WIGTH SQUARE_SIZE*SCORE_HORIZONTAL
#define DISPLAY_SCORE_HEIGTH SQUARE_SIZE*SCORE_VERTICAL
#define DISPLAY_SCORE_X SQUARE_SIZE*SCORE_X
#define DISPLAY_SCORE_Y SQUARE_SIZE*SCORE_Y

// Game Over Window
#define GAME_OVER_HORIZONTAL_SIZE 25
#define GAME_OVER_VERTICAL_SIZE 10

#define GAME_OVER_MESSAGE_HORIZONTAL 5
#define GAME_OVER_MESSAGE_VERTICAL 2
#define GAME_OVER_MESSAGE_X 2
#define GAME_OVER_MESSAGE_Y 4

// Display Game Over Window
#define GAME_OVER_DISPLAY_WIDTH SQUARE_SIZE*GAME_OVER_HORIZONTAL_SIZE
#define GAME_OVER_DISPLAY_HEIGTH SQUARE_SIZE*GAME_OVER_VERTICAL_SIZE

#define DISPLAY_GAME_OVER_MESSAGE_WIGTH SQUARE_SIZE*GAME_OVER_MESSAGE_HORIZONTAL
#define DISPLAY_GAME_OVER_MESSAGE_HEIGTH SQUARE_SIZE*GAME_OVER_MESSAGE_VERTICAL
#define DISPLAY_GAME_OVER_MESSAGE_X SQUARE_SIZE*GAME_OVER_MESSAGE_X
#define DISPLAY_GAME_OVER_MESSAGE_Y SQUARE_SIZE*GAME_OVER_MESSAGE_Y

// Colors
#define BLACK_COLOR { .r = 0, .g = 0, .b = 0, .a = 255 }
#define WHITE_COLOR { .r = 255, .g = 255, .b = 255, .a = 255 }
#define GREY_COLOR { .r = 128, .g = 128, .b = 128, .a = 255 }
#define BLUE_COLOR { .r = 0, .g = 0, .b = 255, .a = 255 }
#define VIOLET_COLOR { .r = 127, .g = 0, .b = 255, .a = 255 }
#define RED_COLOR { .r = 255, .g = 0, .b = 0, .a = 255 }
#define GREEN_COLOR { .r = 102, .g = 204, .b = 0, .a = 255 }
#define YELLOW_COLOR { .r = 255, .g = 255, .b = 0, .a = 255 }
#define LIGHT_BLUE_COLOR { .r = 0, .g = 204, .b = 204, .a = 255 }
#define ORANGE_COLOR { .r = 255, .g = 128, .b = 0, .a = 255 }
#define MEDIUM_BLUE_COLOR { .r = 255, .g = 0, .b = 255, .a = 255 }

// Audio
#define BEGINNING_MUSIC_FILE "../sounds/beginning.wav"
#define CHOMP_MUSIC_FILE "../sounds/chomp.wav"
#define DEATH_MUSIC_FILE "../sounds/death.wav"
#define EATFRUIT_MUSIC_FILE "../sounds/eatfruit.wav"
#define EATGHOST_MUSIC_FILE "../sounds/eatghost.wav"
#define EXTRAPAC_MUSIC_FILE "../sounds/extrapac.wav"
#define INTERMISSION_MUSIC_FILE "../sounds/intermission.wav"
