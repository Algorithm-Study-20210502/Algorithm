// ~ 30분, dfs, bfs를 합쳐야한다는게
//15:03 ~ 16:45
//18:22 ~ 20:06
#include <stdio.h>
#define NOT_VISIT 0
#define VISIT_RG 1
#define VISIT_B 2
#define VISIT_BLIND 3
#define TRUE 1
#define FALSE 0

int N;
char arr[100][100];

int normalPerson = 1;
int normalVisit[100][100];
int blindPerson = 1;
int blindVisit[100][100];

int queueStartIndex = 0;
int queueEndIndex = 0;
int queueArr[10000]; //X = value / 100; Y = value % 100;
int queueX = 0, queueY = 0;

void GetNormalArea(int y, int x, int isRoot) {
    // printf("qS : %2d, qE : %2d\t\t", queueStartIndex, queueEndIndex);
    char curColor = arr[y][x];
    normalVisit[y][x] = curColor == 'B' ? VISIT_B : VISIT_RG;

    if(x + 1 < N && normalVisit[y][x+1] == NOT_VISIT) {
        if(arr[y][x+1] != curColor) {
            // printf("rightQueue\t");
            queueArr[queueEndIndex++] = (x+1) * 100 + y;
        }
        else {
            // printf("right %d, %d, %c, %c\n", x,y, curColor, arr[y][x+1]);
            GetNormalArea(y,x+1, FALSE);
        }
    }

    if(y + 1 < N && normalVisit[y+1][x] == NOT_VISIT) {
        if(arr[y+1][x] != curColor) {
            // printf("downQueue\t");
            queueArr[queueEndIndex++] = x * 100 + (y+1);
        }
        else {
            // printf("down %d, %d, %c, %c\n", x,y, curColor, arr[y+1][x]);
            GetNormalArea(y+1,x,FALSE);
        }
    }

    if(x - 1 >= 0 && normalVisit[y][x-1] == NOT_VISIT) {
        if(arr[y][x-1] != curColor) {
            // printf("leftQueue\t");
            queueArr[queueEndIndex++] = (x-1) * 100 + y;
        }
        else {
            // printf("left %d, %d, %c, %c\n", x,y,curColor, arr[y][x-1]);
            GetNormalArea(y,x-1,FALSE);
        }
    }

    if(y - 1 >= 0 && normalVisit[y-1][x] == NOT_VISIT) {
        if(arr[y-1][x] != curColor) {
            // printf("topQueue\t");
            queueArr[queueEndIndex++] = x * 100 + (y-1);
        }
        else {
            // printf("top %d, %d, %c, %c\n", x,y,curColor, arr[y-1][x]);
            GetNormalArea(y-1,x,FALSE);
        }
    }

    while (isRoot && queueEndIndex-queueStartIndex > 0) {
        queueX = queueArr[queueStartIndex] / 100;
        queueY = queueArr[queueStartIndex] % 100;
        // printf("qS : %2d, qE : %2d", queueStartIndex, queueEndIndex);
        // printf("\tqX : %2d, qY : %2d\n", queueX, queueY);
        queueStartIndex++;
        if(normalVisit[queueY][queueX] == NOT_VISIT) {
            // printf("NOT VISIT %d,%d\n", queueX, queueY);
            normalPerson++;
            GetNormalArea(queueY, queueX,TRUE);
        }
    }

    // printf("out \n");
}

void GetBlindArea(int y, int x, int isRoot) {
    int curColor = normalVisit[y][x];
    blindVisit[y][x] = VISIT_BLIND;

    if(x + 1 < N && blindVisit[y][x+1] == NOT_VISIT) {
        if(normalVisit[y][x+1] != curColor) {
            queueArr[queueEndIndex++] = (x+1) * 100 + y;
        }
        else {
            GetBlindArea(y,x+1, FALSE);
        }
    }

    if(y + 1 < N && blindVisit[y+1][x] == NOT_VISIT) {
        if(normalVisit[y+1][x] != curColor) {
            queueArr[queueEndIndex++] = x * 100 + (y+1);
        }
        else {
            GetBlindArea(y+1,x,FALSE);
        }
    }

    if(x - 1 >= 0 && blindVisit[y][x-1] == NOT_VISIT) {
        if(normalVisit[y][x-1] != curColor) {
            queueArr[queueEndIndex++] = (x-1) * 100 + y;
        }
        else {
            GetBlindArea(y,x-1,FALSE);
        }
    }

    if(y - 1 >= 0 && blindVisit[y-1][x] == NOT_VISIT) {
        if(normalVisit[y-1][x] != curColor) {
            queueArr[queueEndIndex++] = x * 100 + (y-1);
        }
        else {
            GetBlindArea(y-1,x,FALSE);
        }
    }

    while (isRoot && queueEndIndex-queueStartIndex > 0) {
        queueX = queueArr[queueStartIndex] / 100;
        queueY = queueArr[queueStartIndex] % 100;
        queueStartIndex++;
        if(blindVisit[queueY][queueX] == NOT_VISIT) {
            blindPerson++;
            GetBlindArea(queueY, queueX,TRUE);
        }
    }
}

int main() {
    scanf("%d ", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            scanf("%c", &arr[i][j]);
        if(i != N-1) scanf("%c", &arr[i+1][0]);
    }
        

    GetNormalArea(0,0, TRUE);
    queueStartIndex = 0;
    queueEndIndex = 0;
    GetBlindArea(0,0, TRUE);

    printf("%d %d", normalPerson, blindPerson);
}