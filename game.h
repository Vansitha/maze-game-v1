#ifndef GAME_H
#define GAME_H

#define WALL 'o'
#define GOAL 'x'
#define PLAYERUP '^'
#define PLAYERDOWN 'v'
#define PLAYERLEFT '<'
#define PLAYERRIGHT '>'
#define BLANK ' '

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

#define TOP_BORDER 0
#define LEFT_BORDER 0

void updateMap(char **map, int mapRow, int mapCol, int *playerPos, int *goalPos, char input);
void moveUp(char **map, int *playerPosR, int *playerPosC);
void moveDown(char **map, int *playerPosR, int *playerPosC, int maxRowBorder);
void moveRight(char **map, int *playerPosR, int *playerPosC, int maxColBorder);
void moveLeft(char **map, int *playerPosR, int *playerPosC);

#endif