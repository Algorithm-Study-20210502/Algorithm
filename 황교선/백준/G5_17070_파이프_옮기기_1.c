#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define VERTICAL 1
#define HORIZONTAL 2
#define DIAGONAL 3

void scanInput(int *N, int ***arrayPointer) {
    scanf("%d", N);

    int** array = (int**)malloc(sizeof(int*)*(*N));
    for(int i = 0; i < *N; i++) 
        array[i] = (int*)malloc(sizeof(int)*(*N));
    
    for(int i = 0; i < *N; i++)
        for(int j = 0; j < *N; j++) 
            scanf("%d", &array[i][j]);

    *arrayPointer = array;
}

int findPath(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY, int direction, int N, int **array) {
    static int solvedCnt = 0;
    // printArray(topLeftX,topLeftY,bottomRightX,bottomRightY, N, array);
    int rightEmpty = FALSE, downEmpty = FALSE, diagonalEmpty = FALSE;

    if(bottomRightX == N-1 && bottomRightY == N-1) {
        solvedCnt++;
        // printf("Solved Increase\n");
        return;
    }

    // printf("FindPath(%d,%d),(%d,%d) -> ", topLeftX,topLeftY,bottomRightX,bottomRightY);
    if(bottomRightY+1 < N && array[bottomRightX][bottomRightY+1] == 0)
        rightEmpty = TRUE;
    if(bottomRightX+1 < N && array[bottomRightX+1][bottomRightY] == 0)
        downEmpty = TRUE;
    if(rightEmpty == TRUE && downEmpty == TRUE && array[bottomRightX+1][bottomRightY+1] == 0)
        diagonalEmpty = TRUE;

    switch (direction) 
    {
    case HORIZONTAL:
        if(rightEmpty == TRUE) {
            // printf("(%d,%d),(%d,%d),HORIZONTAL HORIZONTAL\n", bottomRightX,bottomRightY,bottomRightX,bottomRightY+1);
            findPath(bottomRightX, bottomRightY, bottomRightX, bottomRightY+1, HORIZONTAL, N, array);
            if(diagonalEmpty == TRUE) {
                // printf("FindPath(%d,%d),(%d,%d) -> ", topLeftX,topLeftY,bottomRightX,bottomRightY);
                // printf("(%d,%d),(%d,%d),HORIZONTAL DIANOGAL\n", bottomRightX,bottomRightY,bottomRightX+1,bottomRightY+1);
                findPath(bottomRightX, bottomRightY, bottomRightX+1, bottomRightY+1, DIAGONAL, N, array);
            }
        }
        break;

    case VERTICAL:
        if(downEmpty == TRUE) {
            // printf("(%d,%d),(%d,%d),VERTICAL VERTICAL\n", bottomRightX,bottomRightY,bottomRightX+1,bottomRightY);
            findPath(bottomRightX, bottomRightY, bottomRightX+1, bottomRightY, VERTICAL, N, array);
            if(diagonalEmpty == TRUE) {
                // printf("FindPath(%d,%d),(%d,%d) -> ", topLeftX,topLeftY,bottomRightX,bottomRightY);
                // printf("(%d,%d),(%d,%d),VERTICAL DIANOGAL\n", bottomRightX,bottomRightY,bottomRightX+1,bottomRightY+1);
                findPath(bottomRightX, bottomRightY, bottomRightX+1, bottomRightY+1, DIAGONAL, N, array);
            }
        }
        break;

    case DIAGONAL:
        if(rightEmpty == TRUE) {
            findPath(bottomRightX, bottomRightY, bottomRightX, bottomRightY+1, HORIZONTAL, N, array);
        }

        if(downEmpty == TRUE) {
            // printf("(%d,%d),(%d,%d),DIANOGAL VERTICAL\n", bottomRightX,bottomRightY,bottomRightX+1,bottomRightY);
            findPath(bottomRightX, bottomRightY, bottomRightX+1, bottomRightY, VERTICAL, N, array);
        }

        if(diagonalEmpty == TRUE) {
            // printf("(%d,%d),(%d,%d),DIANOGAL DIANOGAL\n", bottomRightX,bottomRightY,bottomRightX+1,bottomRightY+1);
            findPath(bottomRightX, bottomRightY, bottomRightX+1, bottomRightY+1, DIAGONAL, N, array);
        }
        break;
    }

    return solvedCnt;
}

int main() {
    int N = 0;
    int **array;
    int solvedCnt = 0;

    scanInput(&N, &array);
    solvedCnt = findPath(0, 0, 0, 1, HORIZONTAL, N, array);
    printf("%d\n", solvedCnt);
}