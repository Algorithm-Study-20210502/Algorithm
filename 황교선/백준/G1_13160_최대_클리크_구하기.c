//13:39 ~ 14:10 문제 이해
//14:45 ~ 15:34 quicksort node 적용 ~ 16:08 ~ 16:48 ~ 17:05

#include <stdio.h>
#define MAX 300000
typedef struct node {
    int order;
    int start;
    int end;
} Node;

int N;
Node nodes[MAX];
int startIndex, endIndex, setLength = 1;

void ScanInputs() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &nodes[i].start, &nodes[i].end);
        nodes[i].order = i+1;
    }
}

void PrintNodes() {
    printf("\n\n");
    for(int i = 0; i < N; i++) {
        printf("%d %d %d\n", nodes[i].order, nodes[i].start, nodes[i].end);
    }
    printf("\n\n");
}

void Swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(int left, int right) {
    if(left >= right) return;
    Node* pivot = &nodes[left];
    int leftIndex = left;
    int rightIndex = right+1;

    do {
        do {
            leftIndex++;
            if(nodes[leftIndex].start < pivot->start) continue;
            else if(nodes[leftIndex].start == pivot->start && nodes[leftIndex].end < pivot->end) continue;
            else break;
        } while(leftIndex <= right);
        do {
            rightIndex--;
            if(nodes[rightIndex].start > pivot->start) continue;
            else if(nodes[rightIndex].start == pivot->start && nodes[rightIndex].end > pivot->end) continue;
            else break;
        } while(rightIndex >= left);
        if(leftIndex < rightIndex) {
            Swap(&nodes[leftIndex], &nodes[rightIndex]);
            // if(nodes[leftIndex].start > nodes[rightIndex].start) Swap(&nodes[leftIndex], &nodes[rightIndex]);
            // else if(nodes[leftIndex].start == nodes[rightIndex].start && nodes[leftIndex].end > nodes[rightIndex].end) Swap(&nodes[leftIndex], &nodes[rightIndex]);
        }
    } while(leftIndex < rightIndex);
    Swap(pivot, &nodes[rightIndex]);
    QuickSort(left, rightIndex - 1);
    QuickSort(rightIndex + 1, right);
}

void GetLargeSetIndex() {
    int largestSetStartIndex = 0;
    int largestSetEndIndex = 0;
    int largestSetLength = 1;

    int currentSetStartIndex = 0;
    int currentSetEndIndex = 0;
    int currentSetLength = 1;

    for(int i = 1; i < N; i++) {
        if(nodes[i].start <= nodes[currentSetStartIndex].end) {
            currentSetLength++;
            currentSetEndIndex = i;
        }
        else {
            if(currentSetLength > largestSetLength) {
                largestSetLength = currentSetLength;
                largestSetStartIndex = currentSetStartIndex;
                largestSetEndIndex = currentSetEndIndex;
            }

            currentSetLength = 1;
            currentSetStartIndex = i;
            currentSetEndIndex = i;
        }
    }

    if(currentSetLength > largestSetLength) {
        largestSetLength = currentSetLength;
        largestSetStartIndex = currentSetStartIndex;
        largestSetEndIndex = currentSetEndIndex;
    }

    startIndex = largestSetStartIndex;
    endIndex = largestSetEndIndex;
    setLength = largestSetLength;
}

void PrintSet() {
    printf("%d\n", setLength);
    for(int i = startIndex; i < endIndex; i++) {
        printf("%d ", nodes[i].order);
    }
    printf("%d", nodes[endIndex].order);
}

int main() {
    ScanInputs();
    QuickSort(0, N-1);
    PrintNodes();
    GetLargeSetIndex();
    PrintSet();
}

/*
11 
5 10
5 9
5 11
2 4
5 12
4 6
5 7
5 8
5 8
4 5
1 3
*/