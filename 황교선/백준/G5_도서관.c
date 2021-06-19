//16:13 ~ 17:55
//12:25 ~ 13:03 ~ 디버깅 ~ 13:18
#include <stdio.h>
#define ABS(v) v < 0 ? -v : v
#define LEFT -1
#define RIGHT 1
#define FINISH 1
#define TRUE 1
#define FALSE 0

int N, M;
int bookPos[10000];
int walkCnt = 0;

int bookRemain;
int absPos0;
int absPosN;
int farDirection;

int currentPos;
int currentIndex;

void scanInput() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &bookPos[i]);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int left, int right) {
    if(left >= right) return;
    int* pivot = &bookPos[left];
    int leftIndex = left;
    int rightIndex = right+1;

    do {
        do leftIndex++; while(leftIndex <= right && bookPos[leftIndex] < *pivot);
        do rightIndex--; while(rightIndex >= left && bookPos[rightIndex] > *pivot);
        if(leftIndex < rightIndex) swap(&bookPos[leftIndex], &bookPos[rightIndex]);
    } while(leftIndex < rightIndex);
    swap(pivot, &bookPos[rightIndex]);
    quickSort(left, rightIndex - 1);
    quickSort(rightIndex + 1, right);
}

int returnOnce() {
    absPos0 = ABS(bookPos[0]);
    absPosN = ABS(bookPos[N-1]);
    farDirection = absPos0 > absPosN ? LEFT : RIGHT;
    int isOnlyOneSide = FALSE;
    if(bookPos[0] * bookPos[N-1] > 0)
        isOnlyOneSide = TRUE;

    if(farDirection == LEFT) {
        walkCnt += absPos0;
    }
    else {
        walkCnt += absPosN;
    }

    if(isOnlyOneSide && M >= N) return FINISH;
    return FALSE;
}

void returnLeftSide() {
    if(farDirection == LEFT)
        currentIndex = M;
    else
        currentIndex = 0;
    currentPos = bookPos[currentIndex];

    while(currentPos < 0 && currentIndex < N) {
        walkCnt += 2 * (-currentPos);
        currentIndex += M;
        currentPos = bookPos[currentIndex];
    }
}

void returnRightSide() {
    if(farDirection == LEFT)
        currentIndex = N-1;
    else
        currentIndex = N-1-M;
    currentPos = bookPos[currentIndex];

    while(currentPos > 0 && currentIndex >= 0) {
        walkCnt += 2 * currentPos;
        currentIndex -= M;
        currentPos = bookPos[currentIndex];
    }
}

void returnBook() {
    bookRemain = N-1;

    if(returnOnce() == FINISH) return;
    if(bookPos[0] < 0) 
        returnLeftSide();
    if(0 < bookPos[bookRemain]) 
        returnRightSide();
}

int main() {
    scanInput();
    quickSort(0, N-1);
    returnBook();
    printf("%d", walkCnt);
}