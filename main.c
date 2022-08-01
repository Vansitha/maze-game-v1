#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "generateMap.h"
#include "game.h"
#include "terminal.h"
#include "visibilityF.h"

int main(int argc, char *argv[])
{
	int metadataAmount;
	int mapRow;
	int mapCol;
	int **metadataTable;
	char **map;
	char userInput;
	int initialPlayerPosR;
	int initialPlayerPosC;
	int goalR;
	int goalC;
	int *currPlayerPosR;
	int *currPlayerPosC;
	int i;
	int visibility;

	getMetadata(&metadataTable, &metadataAmount, &mapRow, &mapCol);

	map = (char **)malloc(sizeof(char *) * mapRow);
	for (i = 0; i < mapRow; i++)
	{
		map[i] = (char *)malloc(sizeof(char) * mapCol);
	}

	createMap(map, metadataTable, mapRow, mapCol, metadataAmount);

	initialPlayerPosR = metadataTable[0][0];
	initialPlayerPosC = metadataTable[0][1];
	goalR = metadataTable[1][0];
	goalC = metadataTable[1][1];
	currPlayerPosR = &initialPlayerPosR;
	currPlayerPosC = &initialPlayerPosC;

	for (i = 0; i < metadataAmount; i++)
	{
		free(metadataTable[i]);
	}
	free(metadataTable);
	metadataTable = NULL;

	visibility = DEFAULTVIEW;

#ifdef DARK
	visibility = setVisibility(argc, argv, visibility);
#endif

	displayMap(map, mapRow, mapCol, visibility, currPlayerPosR, currPlayerPosC);
	disableBuffer();

	while ((map[*currPlayerPosR][*currPlayerPosC]) != (map[goalR][goalC]))
	{
		scanf("%c", &userInput);

		updateMap(map, mapRow, mapCol, currPlayerPosR, currPlayerPosC, userInput);
		system("clear");
		displayMap(map, mapRow, mapCol, visibility, currPlayerPosR, currPlayerPosC);

#ifdef DEBUG
		printf("\nPlayerPosR: %d | PlayerPosC: %d\n", *currPlayerPosR, *currPlayerPosC);
		printf("Player: %c\n", map[*currPlayerPosR][*currPlayerPosC]);
#endif
	}

	printf("\nYou win!\n");
	enableBuffer();

	for (i = 0; i < mapRow; i++)
	{
		free(map[i]);
	}
	free(map);
	map = NULL;

	return 0;
}
