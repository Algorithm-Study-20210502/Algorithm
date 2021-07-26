# Algorithm_Theory

## 알고리즘 유형별로 공부하고 공부한 내용을 정리하기

### 그리디

- [그리디](/이형걸/그리디/그리디(Greedy).md) : 매 순간 가장 좋아 보이는 것을 선택하는 알고리즘
  - 현재의 선택이 나중에 미칠 영향에 대해서는 고민하지 않는다.

### 구현

### DFS/BFS

- [그래프(graph)의 기본 구조](/이형걸/DFS,BFS/그래프(Graph)의%20기본%20구조.md) : 노드(Node) 와 간선(Edge) 으로 표현되며, 이때 노드를 정점(Vertex) 이라고도 말한다. 
- [DFS(Depth-First-Search)](/이형걸/DFS,BFS/DFS(Depth-First_Search).md) : 깊이 우선 탐색, 그래프에서 깊은 부분을 우선적으로 탐색하는 알고리즘 
- [BFS(Breadth-First-Search)](/이형걸/DFS,BFS/BFS(Breadth-First-Search).md) : 넓이 우선 탐색, 가까운 노드부터 탐색하는 알고리즘 

### 정렬

### 이진 탐색

- [순차 탐색(Sequential Search)](/이형걸/이분%20탐색/순차%20탐색(Sequential%20Search).md) : 리스트 안에 있는 특정한 데이터를 찾기 위해 앞에서부터 데이터를 하나씩 차례대로 확인하는 방법

- [이분 탐색(Binary Search)](/이형걸/이분%20탐색/이분%20탐색(Binary%20Search).md) : 범위를 반으로 쪼개면서 탐색하는 알고리즘

- [트리 자료 구조, 이진 탐색 트리](/이형걸/이분%20탐색/트리%20자료%20구조,%20이진%20탐색%20트리.md) : 큰 데이터를 처리하는 소프트웨어 는 대부분 데이터를 트리 자료 구조로 저장 해서 이진 탐색 과 같은 탐색 기법을 이용해 빠르게 탐색이 가능하다.
 
### 다이나믹 프로그래밍

### 최단 경로

* [다익스트라 알고리즘(Dijkstra's algorithm)](/이형걸/최단%20경로/다익스트라%20알고리즘(Dijkstra's%20algorithm).md) : 한 지점에서 다른 특정 지점까지의 최단 경로를 구해야 하는 경우
  *  해당 노드를 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블을 갱신한다.
* [플로이드 워샬 알고리즘(Floyd-Warshall Algorithm)](/이형걸/최단%20경로/플로이드%20워샬%20알고리즘(Floyd-Warshall%20Algorithm).md) : '모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구해야 하는 경우'
  * 노드의 개수가 N개일 때, 매 단계마다 점화식에 맞게 2차원 리스트를 갱신한다. 

* [벨만-포드 알고리즘(Bellman-Ford's Algorithm)](/이형걸/최단%20경로/벨만-포드%20알고리즘(Bellman-Ford's%20Algorithm).md) : 음의 간선이 포함된 상황에서도 사용, 최단 거리를 구할 수 있다. 
  * 음의 간선의 순환을 감지 할 수 있다. 

### 그래프 이론
* [서로소 집합(Disjoint Sets)](/이형걸/그래프%20이론/서로소%20집합(Disjoint%20Sets)_유니온%20파인드(Union-Find).md) : 서로소 집합을 이용한 사이클 판별
* [최소 신장 트리(Minimum Spanning Tree)](/이형걸/그래프%20이론/최소%20신장%20트리(Minimum%20Spanning%20Tree).md) : 가장 적은 비용으로 모든 노드를 연결
* [위상 정렬(Topological Sort)](/이형걸/그래프%20이론/위상%20정렬(Toplogical%20Sort).md) : 방향 그래프의 모든 노드를 '방향성에 거스르지 않도록 순서대로 나열하는 것'
### 해시

### 조합론

#### 참고

- 순열 : https://yabmoons.tistory.com/100?category=838490
- 조합 : https://yabmoons.tistory.com/99

### 투 포인터

