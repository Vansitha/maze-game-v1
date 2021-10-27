#include <stdio.h>
#include "generateMap.h"

void createMap(char **map, int **metadataTable, int mapRow, int mapCol, int metadataAmount)
{

	int row;
	int col;

	int maxRow;
	int maxCol;

	int tableCol;

	tableCol = 3;

	maxRow = mapRow - 1;
	maxCol = mapCol - 1;

	for (row = 0; row < mapRow; row++)
	{
		for (col = 0; col < mapCol; col++)
		{

			if ((col >= 0) && (col <= maxCol) && ((row == 0) || (row == maxRow)))
			{
				map[row][col] = '-';
			}

			else if ((row >= 0) && (row < maxRow) && ((col == 0) || (col == maxCol)))
			{
				map[row][col] = '|';
			}

			else
			{
				map[row][col] = ' ';
			}
		}
	}
	map[0][0] = '#';
	map[0][mapCol - 1] = '#';
	map[mapRow - 1][0] = '#';
	map[mapRow - 1][mapCol - 1] = '#';

	for (row = 0; row < metadataAmount; row++)
	{
		for (col = 0; col < tableCol; col++)
		{
			if (metadataTable[row][2] == 0)
			{
				map[metadataTable[0][0]][metadataTable[0][1]] = '^';
			}
			if (metadataTable[row][2] == 1)
			{
				map[metadataTable[1][0]][metadataTable[1][1]] = 'x';
			}
			if (metadataTable[row][2] == 2)
			{
				map[metadataTable[row][0]][metadataTable[row][1]] = 'o';
			}
		}
	}
}