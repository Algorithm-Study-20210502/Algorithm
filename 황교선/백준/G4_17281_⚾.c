#include <stdio.h>
#define FALSE 0
#define TRUE 1

#define OUT 0
#define BASE1 1
#define BASE2 2
#define BASE3 3
#define HOMERUN 4

#define PERSON 1
#define NONE 0
/*
21년 5월 14일
17:02 ~ 17:48 문제만 봄 문제의 정의가 좀 모호했음 질문글에서 참조 ~ 
11:39 ~ C언어로 시작 ~ 12:55 순열 알고리즘 이해(아직 부족) ~ 14:28
https://buddev.tistory.com/26

이전에 풀면 좋은 문제
모든 순열 : https://www.acmicpc.net/problem/10974
*/

int N;
int innings[50][9];

int playerOrder[9] = {0,1,2,3,4,5,6,7,8};
int currentOrder[9];
int currentPlayer = 0;
int currentBase[3] = {0,0,0};

void scanInput() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < 9; j++) 
            scanf("%d", &innings[i][j]);
}

void copyOrder() {
    for(int i = 0; i < 9; i++) 
        currentOrder[i] = playerOrder[i];
}

void makeN1toN4() {
    int temp = currentOrder[0];
    currentOrder[0] = currentOrder[1];
    currentOrder[1] = currentOrder[2];
    currentOrder[2] = currentOrder[3];
    currentOrder[3] = temp;
}

void swapOrder(int i, int j) {
    int temp = playerOrder[i];
    playerOrder[i] = playerOrder[j];
    playerOrder[j] = temp;
}


int makePlayerOrder() {
    int i = 8, j = 8;
    while(i > 1 && playerOrder[i - 1] > playerOrder[i]) i--;
    if(i == 1) return FALSE;

    while(playerOrder[i-1] > playerOrder[j]) j--;
    swapOrder(i-1, j);

    j = 8;
    while(i < j) swapOrder(i++, j--);
    return TRUE;
}

int getScoreFromCurrentGame() {
    int totalScore = 0;
    currentPlayer = 0;

    for(int currentInning = 0; currentInning < N; currentInning++) {
        for(int i = 0; i < 3; i++)
            currentBase[i] = NONE;

        int out = 0;
        while(out < 3) {
            int swing = innings[currentInning][currentOrder[currentPlayer]];
            switch (swing)
            {
            case OUT:
                out++;
                break;
            case BASE1:
                if(currentBase[2] == PERSON) totalScore++;
                currentBase[2] = currentBase[1];
                currentBase[1] = currentBase[0];
                currentBase[0] = PERSON;
                break;
            case BASE2:
                if(currentBase[2] == PERSON) totalScore++;
                if(currentBase[1] == PERSON) totalScore++;
                currentBase[2] = currentBase[0];
                currentBase[1] = PERSON;
                currentBase[0] = NONE;
                break;
            case BASE3:
                if(currentBase[2] == PERSON) totalScore++;
                if(currentBase[1] == PERSON) totalScore++;
                if(currentBase[0] == PERSON) totalScore++;
                currentBase[2] = PERSON;
                currentBase[1] = NONE;
                currentBase[0] = NONE;
                break;
            case HOMERUN:
                if(currentBase[2] == PERSON) totalScore++;
                if(currentBase[1] == PERSON) totalScore++;
                if(currentBase[0] == PERSON) totalScore++;
                totalScore++;
                currentBase[2] = NONE;
                currentBase[1] = NONE;
                currentBase[0] = NONE;
                break;
            }
            currentPlayer = (currentPlayer+1) % 9;
        }
    }

    return totalScore;
}

int main() {
    int highestScore = 0;

    scanInput();
    do {
        copyOrder();
        makeN1toN4();
        int currentScore = getScoreFromCurrentGame();
        if(highestScore < currentScore) 
            highestScore = currentScore;
    } while(makePlayerOrder());

    printf("%d", highestScore);
}