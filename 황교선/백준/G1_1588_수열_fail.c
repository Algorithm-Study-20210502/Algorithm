//13:35 ~ 14:50 메모리 초과
#include <stdio.h>
#include <stdlib.h>

const int SeriesRule[3][3] = {{1,3,2},{2,1,1},{2,3,2}};

void scanInput(int *firstNum, int *left, int *right, int *N) {
    scanf("%d", firstNum);
    scanf("%d", left);
    scanf("%d", right);
    scanf("%d", N);
}

long getSizeOfArray(int N) {
    long size = 1;

    for(int i = 0; i < N; i++) {
        size *= 3;
    }

    return size;
}

void makeArray(int N, int **array) {
    int *tempArray;
    long size = getSizeOfArray(N);

    tempArray = (int*)malloc(sizeof(int)*size);
    *array = tempArray;
}

void copyArray(int* origin, int* duplicated, long size) {
    for(long i = 0; i < size; i++) {
        duplicated[i] = origin[i];
    }
}

// void printArray(int* array, long size) {
//     for(long i = 0; i < size; i++) {
//         printf("%d ", array[i]);
//     }
//     printf("\n");
// }

void increaseSeries(int N, int *array) {
    static int curSecond = 0;
    long curArraySize;
    int *tempArray;

    curArraySize = getSizeOfArray(curSecond);
    // printf("curArraySize : %ld\n", curArraySize);
    makeArray(curArraySize, &tempArray);
    copyArray(array, tempArray, curArraySize);
    // printf("beforeArray\n");
    // printArray(array, curArraySize);

    for(long i = 0; i <= curSecond; i++) {
        array[i*3] = SeriesRule[tempArray[i]-1][0];
        array[i*3+1] = SeriesRule[tempArray[i]-1][1];
        array[i*3+2] = SeriesRule[tempArray[i]-1][2];
    }
    // printf("AfterArray\n");
    // printArray(array, curArraySize);

    free(tempArray);

    curSecond++;
    if(curSecond <= N)
        increaseSeries(N, array);
    else
        return;
}

void countElementBetween(int left, int right, int *oneTotal, int *twoTotal, int *threeTotal, int N, int *array) {
    int one = 0, two = 0, three = 0;
    long sizeOfArray = getSizeOfArray(N);

    for(long i = left; i <= right; i++) {
        int elementOfIndex = array[i];
        switch (elementOfIndex)
        {
        case 1:
            one++;
            break;
        case 2:
            two++;
            break;
        case 3:
            three++;
            break;
        }
    }

    *oneTotal = one;
    *twoTotal = two;
    *threeTotal = three;
}

int main() {
    int firstNum;
    int left, right;
    int N;

    int oneTotal = 0;
    int twoTotal = 0;
    int threeTotal = 0;

    int *array;

    scanInput(&firstNum, &left, &right, &N);
    makeArray(N, &array);
    array[0] = firstNum;
    increaseSeries(N, array);
    countElementBetween(left, right, &oneTotal, &twoTotal, &threeTotal, N, array);

    printf("%d %d %d", oneTotal, twoTotal, threeTotal);
}
