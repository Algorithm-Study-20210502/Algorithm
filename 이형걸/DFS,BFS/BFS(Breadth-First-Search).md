# BFS(Breadth-First-Search)


`BFS(Breadth-First-Search)` : 넓이 우선 탐색, **가까운 노드부터 탐색하는 알고리즘**

## 특징

- 인접한 노드를 반복적으로 queue에 넣도록 알고리즘을 작성하면 자연스럽게 먼저 들어온 것이 먼저 나가게 되어, 가까운 노드부터 탐색을 진행하게 된다.

- 재귀함수로 DFS를 구현하면 컴퓨터 시스템의 동작 특성상 실제 프로그램의 수행 시간은 느려질 수 있다. 따라서 **stack라이브러리를 이용해 시간 복잡도를 완화하는 테크닉이 필요**할 때도 있다.
  - 하지만, 코딩테스트에서는 **보통 DFS 보다는 BFS 구현이 조금 더 빠르게 동작한다**는 정도로 기억하자.  

## 구현법

BFS는 FIFO 방식인 queue 자료구조를 활용한다.

1. 탐색 시작 노드를 queue에 삽입하고 방문 처리를 한다.

2. queue에서 노드를 꺼내 해당 노드의 인접 노드 중에서 방문하지 않은 노드를 모두 queue에 삽입하고 방문 처리를 한다. 

3. 2번의 과정을 더 이상 수행할 수 없을 때까지 반복한다.

```c++
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[9];
vector<int> graph[9];

// BFS 함수 정의
void bfs(int start) {
    queue<int> q;

    q.push(start);

    // 현재 노드를 방문 처리
    visited[start] = true;

    // 큐가 빌 때까지 반복
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        // 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for(int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main(void) {

    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);
    
    graph[2].push_back(1);
    graph[2].push_back(7);
    
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
     
    graph[4].push_back(3);
    graph[4].push_back(5);
     
    graph[5].push_back(3);
    graph[5].push_back(4);
     
    graph[6].push_back(7);
     
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);
     
    graph[8].push_back(1);
    graph[8].push_back(7);
    
    bfs(1);
}
```

## 시간복잡도

queue라이브러리를 사용하는 것이 좋으며, 데이터의 개수가 N개인 경우 **`O(N)`** 의 시간이 소요된다는 특징이 있다.

## 활용

### weight사 없는 graph에서의 최단거리

Graph의 각 edge에 weight가 없을 때 (즉, 모든 edge가 동일한 weight를 가질 때)
- BFS 알고리즘으로 간단하게 최단 경로를 찾을 수 있다.

```c++
#include <iostream>
#include <vector>
#include <queue>

vector<int> dist(N);

void bfs(int start) {
    dist.assign(N, -1);

    queue<int> q;
    q.push(start);

    dist[start] = 0;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int next : edges[cur]) {
            if(dist[next] >= 0) {
                continue;
            }

            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }
}
```

**풀어보면 좋은 문제** : [백준 실버 1] 미로 탐색(2178번) : https://www.acmicpc.net/problem/2178