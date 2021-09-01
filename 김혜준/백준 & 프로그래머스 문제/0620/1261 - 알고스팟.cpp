#include <iostream>
#include <queue>


using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int N, M;
int dist[101][101];
char arr[101][101];
bool visit[101][101] = { false, };

void input();
void solve();
bool check(int y, int x);

int main()
{
	input();
	solve();

}

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	for (int i = 1; i <=N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
}

void solve()
{
	priority_queue<pair<int,pair<int, int>>> pq;
	pq.push({ 0,{ 1,1 } });

	fill(&dist[0][0], &dist[100][101], 10000000);
	dist[1][1] = 0;

	while (!pq.empty()) {
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int cost;
		if (arr[y][x] == '1')
			cost = 1;
		else
			cost = 0;
		
		pq.pop();

		if (dist[y][x] < cost)
			continue;
		
		visit[y][x] = true;

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + dy[i];
			int nextX = x + dx[i];
			int nextCost;

			if (check(nextY, nextX))
			{
				if (arr[nextY][nextX] == '1')
					nextCost = 1;
				else
					nextCost = 0;

				if (dist[nextY][nextX]>nextCost+dist[y][x])
				{
					dist[nextY][nextX] = nextCost + dist[y][x];
					pq.push({ -dist[nextY][nextX],{ nextY,nextX } });
					
				}
			}
			else
				continue;

			
		}
	}

	cout << dist[N][M];

}

bool check(int y, int x) {
	if (y >= 1 && y <= N && x >= 1 && x <= M && !visit[y][x])
		return true;
	else
		return false;
}