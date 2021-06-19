//10:10 ~ 11:05 제출 ~ 11:55 중단

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//행 = Y, 열 = X
//행 열             ~ 1000000, 1000000
//색종이 수          ~ 100
//잘못 칠해진 칸 수  ~ 1000
#define MAX_HEIGHT 1000000

typedef struct coord {
    int x,y;
} XY;

int Y, X;
int paperCnt;
int mistakeCnt;
XY mistakes[1000];

int highestY = 0;
int smallestPaperSize = 10e9;

void MakeRandomPair() {
    srand(time(NULL));
    for(int i = 0; i < mistakeCnt; i++) {
        mistakes[i].x = rand() % 50;
        mistakes[i].y = rand() % 50;
    }
}

void ScanInput() {
    scanf("%d %d", &Y, &X);
    scanf("%d", &paperCnt);
    scanf("%d", &mistakeCnt);
    for(int i = 0; i < mistakeCnt; i++) {
        scanf("%d %d", &mistakes[i].y, &mistakes[i].x);
    }
}

void PrintMistakes() {
    printf("\n\n");
    for(int i = 0; i < mistakeCnt; i++) {
        printf("(%d,%d)\n", mistakes[i].x, mistakes[i].y);
    }
    printf("\n");
}

void Swap(XY *a, XY *b) {
    XY temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(int left, int right) {
    if(left >= right) return;
    XY* pivot = &mistakes[left];
    int leftIndex = left;
    int rightIndex = right+1;

    do {
        do {
            leftIndex++;
            if(mistakes[leftIndex].x < pivot->x) continue;
            else if(mistakes[leftIndex].x == pivot->x && mistakes[leftIndex].y < pivot->y) continue;
            else break;
        } while(leftIndex <= right);
        do {
            rightIndex--;
            if(mistakes[rightIndex].x > pivot->x) continue;
            else if(mistakes[rightIndex].x == pivot->x && mistakes[rightIndex].y > pivot->y) continue;
            else break;
        } while(rightIndex >= left);
        if(leftIndex < rightIndex) {
            Swap(&mistakes[leftIndex], &mistakes[rightIndex]);
        }
    } while(leftIndex < rightIndex);
    Swap(pivot, &mistakes[rightIndex]);
    QuickSort(left, rightIndex - 1);
    QuickSort(rightIndex + 1, right);
}

void GetHighestY() {
    for(int i = 0; i < mistakeCnt; i++) {
        highestY = highestY > mistakes[i].y ? highestY : mistakes[i].y;
    }
    // printf("highY : %d\n", highestY);
}

int GetSmallestSize() {
    GetHighestY();
    for(int ySize = highestY; ySize <= MAX_HEIGHT; ySize++) {
        int currentUsedPaperCnt = 1;
        int currentPaperXCoord = 1;
        for(int j = 0; j < mistakeCnt; j++) {
            // printf("ySize:%d, curCnt:%d, curX:%d, j:%d\n", ySize,currentUsedPaperCnt,currentPaperXCoord), j;
            if(mistakes[j].x < currentPaperXCoord + ySize) continue;
            if(++currentUsedPaperCnt > paperCnt) break;
            currentPaperXCoord = mistakes[j].x;
        }
        if(currentUsedPaperCnt <= paperCnt) {
            if(ySize < smallestPaperSize) {
                smallestPaperSize = ySize;
                continue;
            }
        }
    }
}

int main() {
    ScanInput();
    // mistakeCnt = 1000;
    // MakeRandomPair();
    // PrintMistakes();
    QuickSort(0, mistakeCnt-1);
    // PrintMistakes();
    GetSmallestSize();
    printf("%d", smallestPaperSize);
}