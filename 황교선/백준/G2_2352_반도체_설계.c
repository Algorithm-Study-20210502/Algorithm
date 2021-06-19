//12:49 ~ 13:10 ~ 14:24 ~ lis 개념 공부
//15:30 ~ 16:08
#include <stdio.h>
#define OUT_OF_INDEX 400001

int N;
int rightNode[40000];

int lisCnt = 0;
int lisList[40000];

void scanInput() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &rightNode[i]);
    }
}

int getIndexFromBinarySearch(int value, int start, int end) {
    if(start > end) return start;
    int middle = (end + start) / 2;

    if(value == lisList[middle])
        return middle;
    else if(value < lisList[middle])
        return getIndexFromBinarySearch(value, start, middle-1);
    else
        return getIndexFromBinarySearch(value, middle+1, end);
}

void getLisList() {
    int curIndex = 1;
    while (curIndex < N)
    {
        int curIndexValue = rightNode[curIndex];
        if(curIndexValue > lisList[lisCnt-1]) {
            lisList[lisCnt] = curIndexValue;
            lisCnt++;
        }
        else {
            lisList[getIndexFromBinarySearch(curIndexValue, 0, lisCnt-1)] = curIndexValue;
        }
        curIndex++;
    }
}

int main() {
    scanInput();
    lisList[lisCnt++] = rightNode[0];
    getLisList();
    printf("%d", lisCnt);
}