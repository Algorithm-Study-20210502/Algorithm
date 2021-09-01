#include <iostream>
#include <vector>

using namespace std;

int N, M, W;
int dist[501];
void input();
void solve();
#define INF 50000000

vector <vector<pair<int, int>>> adj;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        input();
        solve();
    }
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> W;
    int S, E, T;
    adj.resize(N + 1);
    

    for (int i = 0; i < M; i++) {
        cin >> S >> E >> T;
        adj[S].push_back({ E,T });
        adj[E].push_back({ S,T });
    }

    for (int j = 0; j < W; j++) {
        cin >> S >> E >> T;
        adj[S].push_back({ E,-T });
    }

}

void solve() {
    fill(dist, dist + N + 1, INF);
    dist[1] = 0;
    bool minusCycle = false;

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= N; j++) {
            for (auto w : adj[j]) {
                int next = w.first;
                int d = w.second;

                if (dist[next] > d + dist[j]) {
                    dist[next] = dist[j] + d;

                    if (i == N - 1)
                        minusCycle = true;
                }
            }
        }
    }


    if (minusCycle == true)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";

    for (int i = 0; i <= N; i++)
        adj[i].clear();
}