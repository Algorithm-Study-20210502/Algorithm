//21:30 ~ 22:41 조합 ~ 23:29
//09:45 ~ 11:20
#include <stdio.h>

#define MAX_INT 1e8
#define TRUE 1
#define FALSE 0

enum CELL { BLANK = -1, WALL = -2, VIRUS = -3, DEACT = -4};

int arr[50][50];
int N, M;
int curArraySec;
int minSec = MAX_INT;

int blankCnt = 0;
int curBlankCnt = 0;
int virusPosCnt = 0;        //Y * 100 + X;
int virusPosXY[10] = { 0 }; //Y = value / 100, X = value % 100
int mActivate[10] = {0,0,0,0,0,0,0,0,0,0};

int duplicated[50][50];

int queue[100000];
int queueStart = 0;
int queueMiddle = 0;
int prevQueueMiddle = 0;
int queueEnd = 0;
int queY;
int queX;

void infectCellOn(int second) {
    if(duplicated[queY][queX] == BLANK) {
        duplicated[queY][queX] = second;
        curBlankCnt++;
    } 
    else if(duplicated[queY][queX] == DEACT) {
        duplicated[queY][queX] = second;
    }
}

void dequeueAt(int startIndex) {
    queY = queue[startIndex] / 100;
    queX = queue[startIndex] % 100;
}

void enqueueNextCell() {
        if(queX-1 >= 0) {
                if (duplicated[queY][queX-1] == BLANK) {
                    queue[queueEnd++] =  queY * 100 + queX-1;
                }
                if (duplicated[queY][queX-1] == DEACT)
                    queue[queueEnd++] =  queY * 100 + queX-1;
        }
        if(queX+1 < N) {
                if (duplicated[queY][queX+1] == BLANK) {
                    queue[queueEnd++] =  queY * 100 + queX+1;
                }
                if (duplicated[queY][queX+1] == DEACT)
                    queue[queueEnd++] =  queY * 100 + queX+1;
        }
        if(queY-1 >= 0) { 
                if (duplicated[queY-1][queX] == BLANK) {
                    queue[queueEnd++] = (queY-1) * 100 + queX;
                }
                if (duplicated[queY-1][queX] == DEACT)
                    queue[queueEnd++] = (queY-1) * 100 + queX;
        }
        if(queY+1 < N) {
                if (duplicated[queY+1][queX] == BLANK) {
                    queue[queueEnd++] = (queY+1) * 100 + queX;
                }
                if (duplicated[queY+1][queX] == DEACT)
                    queue[queueEnd++] = (queY+1) * 100 + queX;
        }
}

int isCurrentQueueLeft() {
    return queueMiddle - queueStart > 0 ? TRUE : FALSE;
}

int isNextQueueLeft() {
    return queueEnd - queueMiddle > 0 ? TRUE : FALSE;
}

void dequeueNextQueue() {
    prevQueueMiddle = queueMiddle;
    queueMiddle = queueEnd;
}

int isTurnEnd() {
    if(blankCnt == curBlankCnt)
        return TRUE;
    else
        return FALSE;
}

int dfs(int second) {
    printf("sec:%d\n", second);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%c ", duplicated[i][j] == WALL ? '-' : '0'+duplicated[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    while(isCurrentQueueLeft()) {
        dequeueAt(queueStart++);
        printf("[%d:(%d,%d)] ",queueStart, queX, queY);
        infectCellOn(second);
        enqueueNextCell();
    }
    
    if(!isTurnEnd() && isNextQueueLeft()) {
        dequeueNextQueue();
        dfs(second+1);
    } 
}

void scanInput() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
            switch (arr[i][j])
            {
            case 0:
                arr[i][j] = BLANK;
                blankCnt++;
                break;
            case 1:
                arr[i][j] = WALL;
                break;
            case 2:
                virusPosXY[virusPosCnt++] = i * 100 + j;
                arr[i][j] = DEACT;
                break;
            }
        }
    }
}

void getLastTime() {
    curArraySec = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(duplicated[i][j] == BLANK) {
                curArraySec = MAX_INT;
                return;
            }
            if(curArraySec < duplicated[i][j])
                curArraySec = duplicated[i][j];
        }
    }
}

int isOnlyActDeactiveVirusAtLast() {
    if(curArraySec == MAX_INT) return FALSE;

    while(prevQueueMiddle < queueEnd) {
        dequeueAt(prevQueueMiddle++);
        if(arr[queY][queX] == BLANK)
            return FALSE;
    }
    return TRUE;
}

int main() {
    scanInput();
    
    for(int i = 0; i < 1<<virusPosCnt; i++) {
        //셋 활성화 바이러스
        int activatedVirusCnt = 0;
        for(int j = 0; j < virusPosCnt; j++) {
            mActivate[j] = 0;
            if(i&(1<<j)) {
                mActivate[j] = TRUE;
                activatedVirusCnt++;
            }
        }

        //메인 알고리즘
        if(activatedVirusCnt == M) {
            //초기화
            printf("dupStart\n");
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    duplicated[i][j] = arr[i][j];
                    printf("%d ", duplicated[i][j]);
                }
                printf("\n");
            }

            queueStart = 0;
            queueEnd = 0;
            //시작 좌표 바이러스, 큐 삽입
            for(int i = 0; i < virusPosCnt; i++) {
                if(mActivate[i] == TRUE) {
                    queue[queueEnd++] = virusPosXY[i];
                }
            }
            queueMiddle = queueEnd;
            curBlankCnt = 0;
            if(curBlankCnt == blankCnt) {
                printf("0");
                return 0;
            }
            dfs(0);
            getLastTime();
            if(isOnlyActDeactiveVirusAtLast())
                curArraySec--;
            if(minSec > curArraySec)
                minSec = curArraySec;
        }
    }

    printf("%d", minSec == MAX_INT ? -1 : minSec);
}