#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> adj[2000];
bool visit[2000];
bool flag=false;

void dfs(int n,int cnt){
  if(cnt==4){
    flag=true;
    return;
  }
  visit[n]=true;
  
  for(auto w:adj[n]){
    if(visit[w])continue;
    dfs(w,cnt+1);
    if(flag)return;
  }
  visit[n]=false;
}

int main() {
  cin >> N >> M;

  for(int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i=0;i<N;i++){
    dfs(i,0);
    if(flag) break;
  }
  if(flag) cout << 1;
  else cout << 0;

  

}