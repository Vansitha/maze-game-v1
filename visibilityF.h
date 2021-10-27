#ifndef VISIBITLITYF_H
#define VISIBITLITYF_H

#define DEFAULTVIEW 0
#define PLAYERCELL 1

void displayMap(char **map, int mapRow, int mapCol, int visibility, int *currPlayerPosR, int *currPlayerPosC);
int setVisibility(int argc, char *argv[], int visibility);

#endif
