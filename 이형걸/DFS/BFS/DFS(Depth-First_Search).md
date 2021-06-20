# DFS(Depth-Dirst-Search)

`DFS(Depth-Dirst-Search)` : 깊이 우선 탐색, **그래프에서 깊은 부분을 우선적으로 탐색하는 알고리즘**

## 특징

- 특정한 결로로 탐색하다가 특정한 상황에서 최대한 깊숙이 들어가서 노드를 방문한 후, 다시 돌아가 다른 경로로 탐색하는 알고리즘

## 구현법

DFS는 스택 자료구조를 활용하한다.

1. 탐색 시작 노드를 스택에 삽입하고 방문 처리를 한다.

2. 스택의 최상단 노드에 방문하지 않은 노드가 있으면 그 인접 노드를 스택에 넣고 방문 처리를 한다. 
   -  방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼낸다.

3. 2번의 과정을 더 이상 수행할 수 없을 때까지 반복한다.

`방문 처리` 는 스택에 한 번 삽입되어 처리된 노드가 다시 삽입되지 않게 체크하는 것을 의미한다. 방문 처리를 함으로써 각 노드를 한 번씩만 처리할 수 있다.

```c++
#include <iostream>
#include <vector>

using namespace std;

bool visited[9];
vector<int> graph[9];

void dfs(int x);

int main(void) {
    // 노드 1에 연결된 노드 정보 저장 
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);
    
    // 노드 2에 연결된 노드 정보 저장 
    graph[2].push_back(1);
    graph[2].push_back(7);
    
    // 노드 3에 연결된 노드 정보 저장 
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    
    // 노드 4에 연결된 노드 정보 저장 
    graph[4].push_back(3);
    graph[4].push_back(5);
    
    // 노드 5에 연결된 노드 정보 저장 
    graph[5].push_back(3);
    graph[5].push_back(4);
    
    // 노드 6에 연결된 노드 정보 저장 
    graph[6].push_back(7);
    
    // 노드 7에 연결된 노드 정보 저장 
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);
    
    // 노드 8에 연결된 노드 정보 저장 
    graph[8].push_back(1);
    graph[8].push_back(7);
    
    dfs(1);
}

// DFS 함수 정의
void dfs(int x) {

    // 현재 노드를 방문 처리
    visited[x] = true;

    cout << x << ' ';

    // 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i];
        if (!visited[y]) dfs(y);
    }
}
```

## 시간복잡도

실제로는 스택을 쓰지 안아도 되며 탐색을 수행함에 있어서 데이터의 개수가 N개인 경우 **`O(N)`** 의 시간이 소요된다는 특징이 있다.

## 활용

