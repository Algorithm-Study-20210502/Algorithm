# DFS(Depth-First-Search)

`DFS(Depth-First-Search)` : 깊이 우선 탐색, **그래프에서 깊은 부분을 우선적으로 탐색하는 알고리즘**

## 특징

- 특정한 경로로 탐색하다가 특정한 상황에서 최대한 깊숙이 들어가서 노드를 방문한 후, 다시 돌아가 다른 경로로 탐색하는 알고리즘

## 구현법

DFS는 스택 자료구조를 활용한다.

1. 탐색 시작 노드를 스택에 삽입하고 방문 처리를 한다.

2. 스택의 최상단 노드에 방문하지 않은 노드가 있으면 그 인접 노드를 스택에 넣고 방문 처리를 한다. 
   -  방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼낸다.

3. 2번의 과정을 더 이상 수행할 수 없을 때까지 반복한다.

`방문 처리` 는 스택에 한 번 삽입되어 처리된 노드가 다시 삽입되지 않게 체크하는 것을 의미한다. 방문 처리를 함으로써 각 노드를 한 번씩만 처리할 수 있다.

스택 자료구조 대신에 재귀 함수를 이용할 수 있다.

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
void dfs(int cur) {

    // 현재 노드를 방문 처리
    visited[cur] = true;

    // 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i];
        if (!visited[next]) { 
            dfs(next);
        }
    }
}
```

## 시간복잡도

실제로는 스택을 쓰지 안아도 되며 탐색을 수행함에 있어서 데이터의 개수가 N개인 경우 **`O(N)`** 의 시간이 소요된다는 특징이 있다.

## 활용

### Connected Components 

`연결 그래프(Connected Graph)` : 그래프의 component가 1개인 그래프, 즉, 모든 정점들이 연결되어 있는 그래프

`비연결 그래프(Unconnected Graph)` 라면 `dfs`로 모든 정점을 방문할 수 없으므로, **모든 정점을 방문하려면 각 컴포넌트에 속한 정점들 중 하나씩은 방문 시도를 해줘야 한다.**

-  이를 구현하는 가장 쉬운 방법은 **반복문을 돌면서 방문하지 않은 정점을 볼 때마다 DFS를 시작해준다.**
-  이때, **`방문을 시도하는 횟수`** 가 **컴포넌트의 개수**가 된다.

![Count-of-Connected-Components](https://user-images.githubusercontent.com/56071088/126055074-515cc285-f9bd-468c-a998-4be5ed42459b.png)

```c++
#include <iostream>
#include <vector>
#include <cstring>

int N;
vector<vector<int>> edges;
vector<bool> visited;

int dfsAll() {
    int components = 0;
    memset(visited, false, sizeof(visited));

    for(int i = 0; i < N; ++i) {
        if(!visited[i]) {
            int nodes = dfs(i);
            ++components;
            cout << "Components Size : " << nodes << '\n';
        }
    }

    return components;
}

int dfs(int cur) {
    int nodes = 1;
    visited[cur] = true;

    for(int next : edges[cur]) {
        if(!visited[next]) {
            nodes += dfs(next);
        }
    }

    return nodes;
}

int main() {
    ...
    int components = dfsAll();
    ...
    return 0;
}
```

**풀어보면 좋을 문제** : 

[백준 실버 2] 유기농 배추(1012번) : https://www.acmicpc.net/problem/1012

[프로그래머스 레벨 2] 카카오프렌즈 컬러링북 : https://programmers.co.kr/learn/courses/30/lessons/1829
 
### 그래프 싸이클 판별

#### Undirected Graph

DFS를 이용하면 cycle detection을 쉽게 할 수 있다.
- **`Undirected Graph`** 는 **방향성이 없기 때문에 이전에 방문한 노드를 다시 방문하면 cycle이 존재 (단, 직전 방문한 노드는 제외)**

- `Undirected Graph` 의 경우 **`union-find`** 를 이용하는 방법도 있다. 

<img src="https://user-images.githubusercontent.com/56071088/126054876-b0391fe6-f897-4f9d-aa04-6a1619348456.PNG" height="400" width="300">

```c++
vector<vector<int>> edges;
vector<bool> visited;

bool isCyclicGraph(int cur, int parent) {
    visited[cur] = true;
    
    for(int next : edges[cur]) {
        if(!visited[next]) {
            if(isCyclicGraph(next, cur)) {
                return true;
            }
        }
        // undirected graph이므로, 바로 직전에 방문했던 노드가 아니라면 cycle 발생
        // else if(visited[next] &&  next != parent)
        else if(next != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    ...
    if(isCyclicGraph(0, -1)) {
        cout << "Cycle Detected" << '\n';
    }
    ...
    return 0;
}
```

#### Directed Graph

DFS를 이용하면 cycle detection을 쉽게 할 수 있다.
- **`Directed Graph`** 에서는 **DFS 호출 stack 상에서 방문한 node를 다시 방문한 경우만 cycle 존재**

<img src="https://user-images.githubusercontent.com/56071088/126054875-229806d9-f92b-4233-91a8-72af35683ecc.PNG" height="400" width="300">

```c++
vector<vector<int>> edges;
vector<bool> visited;
// 방문하고 아직 stack에 남아있는 노드들을 위한 배열
vector<bool> visitStack;

bool isCyclicGraph(int cur) {
    visited[cur] = true;
    // visiting중이다 라는 것을 표시
    visitStack[cur] = true;

    for(int next : edges[cur]) {
        if(!visited[next]) {
            if(isCyclicGraph(next)) {
                return true;
            }
        }
        else if(visitStack[next])) {
            return true;
        }
    }

    // visit이 다 끝났으므로 visit이 끝났다는 표시
    visitStack[cur] = false;
    
    return false;
}

int main() {
    ...
    if(isCyclicGraph(0)) {
        cout << "Cycle Detected"<< '\n';
    }
    ...
    return 0;
}
```

**풀어보면 좋을 문제** : [백준 골드 4] 텀 프로젝트(9466번) : https://www.acmicpc.net/problem/9466


