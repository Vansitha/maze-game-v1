#include <stdio.h>
#include <stdlib.h>
#include "visibilityF.h"

void displayMap(char **map, int mapRow, int mapCol, int visibility, int *currPlayerPosR, int *currPlayerPosC)
{

    int currRow;
    int currCol;

    int maxVisibleTop;
    int maxVisibleBottom;
    int maxVisibleLeft;
    int maxVisibleRight;

    maxVisibleTop = *currPlayerPosR - (visibility + PLAYERCELL);
    maxVisibleBottom = *currPlayerPosR + (visibility + PLAYERCELL);
    maxVisibleLeft = *currPlayerPosC - (visibility + PLAYERCELL);
    maxVisibleRight = *currPlayerPosC + (visibility + PLAYERCELL);

    for (currRow = 0; currRow < mapRow; currRow++)
    {
        for (currCol = 0; currCol < mapCol; currCol++)
        {
            if (visibility == DEFAULTVIEW)
            {
                printf("%c", map[currRow][currCol]);
            }
            else if (((currRow > maxVisibleTop) && (currRow < maxVisibleBottom)) && ((currCol > maxVisibleLeft) && (currCol < maxVisibleRight)))
            {
                printf("%c", map[currRow][currCol]);
            }

            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int setVisibility(int argc, char *argv[], int visibility)
{

    if (argc <= 1)
    {
        visibility = DEFAULTVIEW;
        printf("NOTE: You did not set the visibility distance!\n");
        printf("Running with default settings\n");
    }
    else
    {
        if (atoi(argv[1]) >= 0)
        {
            visibility = atoi(argv[1]);
        }
        else
        {
            printf("Visibility cannot be negative!\n");
            printf("Running with default settings\n");
        }
    }
    return visibility;
}