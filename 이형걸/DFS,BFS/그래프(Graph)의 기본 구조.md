# 그래프(Graph)의 기본 구조

**`그래프(Graph)`** : **노드(Node)** 와 **간선(Edge)** 으로 표현되며, 이때 노드를 **정점(Vertex)** 이라고도 말한다.

**`그래프 탐색`** : 하나의 노드를 시작으로 다수의 노드를 방문하는 것을 말한다.

- 두 노드가 **간선으로 연결** 되어 있다면 **'두 노드는 인접하다(Adjacent)'** 라고 표현된다.

## 그래프(Graph)의 2가지 표현 방식

`인접 행렬(Adjacent Matrix)` : **2차원 배열** 로 그래프의 연결 관계를 표현하는 방식

`인접 리스트(Adjacent List)` : **List** 로 그래프의 연결 관계를 표현하는 방식

### 인접 행렬(Adjacent Matrix)

`인접 행렬(Adjacent Matrix)` : **2차원 배열** 에 각 노드가 연결된 형태를 기록하는 방식

- 연결이 되어 있지 않은 노드끼리는 무한(Infinity)의 비용이라고 작성한다.
- 논리적으로 될 수 없는 아주 큰 값(999999999, 987654321) 등의 값으로 초기화 하는 경우가 많다.

![인접행렬](https://user-images.githubusercontent.com/56071088/122661479-c479a100-d1c5-11eb-9a60-41ed7dd0e47f.png)


[인접 행렬 방식 예제]

```c++
#include <iostream>

#define INF 999999999 // 무한의 비용 선언

using namespace std;

// 2차원 리스트를 이용해 인접 행렬 표현
int graph[3][3] = {
    {0, 7, 5},
    {7, 0, INF},
    {5, INF, 0}
};

int main(void) {
    // 그래프 출력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
}
```

### 인접 리스트(Adjacent List)

`인접 리스트(Adjacent List)` : 모든 노드에 연결된 노드에 대한 정보를 차례대로 연결하여 저장한다.
- 인접 리스트는 `연결 리스트` 라는 자료구조를 이용해 구현하는데, C++나 자바와 같은 프로그래밍 언어에서는 별도로 연결 리스트 기능을 위한 **표준 라이브러리**를 제공한다.

![인접리스트](https://user-images.githubusercontent.com/56071088/122661488-d9eecb00-d1c5-11eb-8913-75691ef3d930.png)


[인접 리스트 예제]

```c++

// 방법 1
#define MAXN 100
int N;
vector<int> edges[MAXN];

// 방법 2
vector<vector<int>> edges;

void addEdge(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
}

void addDirectedEdge(int u, int v) {
    edges[u].push_back(v);
}

```

```c++
#include <iostream>
#include <vector>

using namespace std;

// 행(Row)이 3개인 인접 리스트 표현
vector<pair<int, int>> graph[3];

int main(void) {
    // 노드 0에 연결된 노드 정보 저장 {노드, 거리}
    graph[0].push_back({1, 7});
    graph[0].push_back({2, 5});

    // 노드 1에 연결된 노드 정보 저장 {노드, 거리}
    graph[1].push_back({0, 7});

    // 노드 2에 연결된 노드 정보 저장 {노드, 거리}
    graph[2].push_back({0, 5});

    // 그래프 출력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            cout << '(' << graph[i][j].first << ',' << graph[i][j].second << ')' << ' ';
        }
        cout << '\n';
    } 
}
```

## 인접 행렬과 인접 리스트 방식의 차이점

- 인접 행렬 방식 
  - **장점** : **특정한 두 노드가 연결되어 있는지 파악**하는데 드는 속도가 빠르다.
  
  - **단점** : 모든 관계를 저장하므로 **노드 개수가 많을수록 메모리가 불필요하게 낭비된다.** 
- 인접 리스트 방식 
  - **장점** : 연결된 정보만을 저장하기 때문에 **메모리를 효율적으로 사용한다.**
  
  - **단점** : 특정한 두 노드가 연결되어 있는지 확인하기 위해 연결된 데이터를 일일이 확인해야 한다. 
 
**`메모리 측면`** : 인접 리스트 방식 > 인접 행렬 방식

**`속도 측면`** : 인접 행렬 방식 > 인접 리스트 방식

특정한 노드와 연결된 모든 인접 노드를 순회해야 하는 경우, 인접 리스트 방식이 인접 행렬 방식에 비해 메모리 공간의 낭비가 적다.

