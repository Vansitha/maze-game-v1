
#include <stdlib.h>
#include "map.h"

void getMetadata(int ***metadataTable, int *metadataAmount, int *mapRow, int *mapCol)
{
    int i;
    int **table;

    *metadataAmount = 17;
    *mapRow = 8;
    *mapCol = 10;

    table = (int **)malloc(sizeof(int *) * (*metadataAmount));

    for (i = 0; i < (*metadataAmount); i++)
    {
        table[i] = (int *)malloc(sizeof(int) * 3);
    }

    table[0][0] = 6;
    table[0][1] = 3;
    table[0][2] = 0;
    table[1][0] = 1;
    table[1][1] = 8;
    table[1][2] = 1;
    table[2][0] = 1;
    table[2][1] = 7;
    table[2][2] = 2;
    table[3][0] = 2;
    table[3][1] = 1;
    table[3][2] = 2;
    table[4][0] = 2;
    table[4][1] = 3;
    table[4][2] = 2;
    table[5][0] = 2;
    table[5][1] = 7;
    table[5][2] = 2;
    table[6][0] = 3;
    table[6][1] = 3;
    table[6][2] = 2;
    table[7][0] = 3;
    table[7][1] = 7;
    table[7][2] = 2;
    table[8][0] = 4;
    table[8][1] = 2;
    table[8][2] = 2;
    table[9][0] = 4;
    table[9][1] = 3;
    table[9][2] = 2;
    table[10][0] = 4;
    table[10][1] = 4;
    table[10][2] = 2;
    table[11][0] = 4;
    table[11][1] = 5;
    table[11][2] = 2;
    table[12][0] = 4;
    table[12][1] = 7;
    table[12][2] = 2;
    table[13][0] = 5;
    table[13][1] = 4;
    table[13][2] = 2;
    table[14][0] = 5;
    table[14][1] = 7;
    table[14][2] = 2;
    table[15][0] = 6;
    table[15][1] = 2;
    table[15][2] = 2;
    table[16][0] = 6;
    table[16][1] = 4;
    table[16][2] = 2;

    *metadataTable = table;
}
