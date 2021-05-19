//14:41 ~ 16:23
#include <stdio.h>
#include <stdlib.h>

typedef struct range {
    int left;
    int right;
}Range;

int firstNum;
long left, right;
short N;

Range *range;
char *tempArray;
char *array;
long curSize = 1;

const char SeriesRule[3][3] = {{'1','3','2'},{'2','1','1'},{'2','3','2'}};

void scanInput() {
    scanf("%d", &firstNum);
    scanf("%ld", &left);
    scanf("%ld", &right);
    scanf("%hd", &N);
}

void makeRangeOfEachSeries() {
    range = (Range*)malloc(sizeof(Range) * N+1);

    range[N].left = left;
    range[N].right = right;
    for(int i = N-1; i >= 0; i--) {
        left = left / 3;
        right = right / 3;
        range[i].left = left;
        range[i].right = right;
    }
}

void increaseSeries() {
    static short curSecond = 1;

    for(long i = 0; i <= curSize; i++) {
        tempArray[i*3] = SeriesRule[array[i]-'1'][0];
        tempArray[i*3+1] = SeriesRule[array[i]-'1'][1];
        tempArray[i*3+2] = SeriesRule[array[i]-'1'][2];
    }

    curSize = range[curSecond].right - range[curSecond].left + 1;

    int index = 0;
    printf("left, right : %d, %d, array : ", range[curSecond].left, range[curSecond].right);
    for(int i = range[curSecond].left; i <= range[curSecond].right; i++) {
        array[index] = tempArray[i];
        index++;
        // printf("%c ", tempArray[i]);
    }
    // printf("\n");

    if(curSecond < N) {
        curSecond++;
        increaseSeries(curSize);
    }
}

void countElement(int *oneTotal, int *twoTotal, int *threeTotal) {
    int one = 0, two = 0, three = 0;

    for(int i = 0; i < curSize; i++) {
        switch (array[i])
        {
        case '1':
            one++;
            break;
        case '2':
            two++;
            break;
        case '3':
            three++;
            break;
        }
    }

    *oneTotal = one;
    *twoTotal = two;
    *threeTotal = three;
}

int main() {
    int oneTotal = 0;
    int twoTotal = 0;
    int threeTotal = 0;

    scanInput();
    tempArray = (char*)malloc(sizeof(char)*(right-left+1));
    array = (char*)malloc(sizeof(char)*(right-left+1));
    array[0] = '0' + firstNum;
    makeRangeOfEachSeries();
    increaseSeries();
    countElement(&oneTotal, &twoTotal, &threeTotal);

    printf("%d %d %d", oneTotal, twoTotal, threeTotal);
}