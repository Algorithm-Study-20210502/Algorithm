#include <iostream>
#include <vector>
#define INF 9999999

using namespace std;

void input();
void solve();

int N,M;
int adj[501][501];
int visit[501];

int main() {
  input();
  solve();
}

void input(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  int a,b;
  fill(&adj[0][0],&adj[N+1][0],INF);

  for(int i=0;i<M;i++){
    cin >> a >> b;
    adj[a][b]=1;
  }
}

void solve(){
  for(int k=1;k<=N;k++){
    for(int i=1;i<=N;i++){
      for(int j=1;j<=N;j++){
        if(adj[i][j]>adj[i][k]+adj[k][j])
          adj[i][j]=adj[i][k]+adj[k][j];
      }
    }
  }

  int ans=0;

  for(int i=1;i<=N;i++){
    int cnt=0;
    for(int j=1;j<=N;j++){
      if(adj[i][j]!=INF || adj[j][i]!=INF)
        cnt++;
    }

    if(cnt==N-1) ans++;
  }

  cout << ans;
}