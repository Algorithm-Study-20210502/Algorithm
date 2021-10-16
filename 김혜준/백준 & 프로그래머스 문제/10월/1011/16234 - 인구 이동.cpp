#include <iostream>
#include <cstring>

using namespace std;

int arr[50][50];
int visit[50][50];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

typedef struct s{
  int total;
  int cnt;
}S;
S s[2501];
int N,L,R;

bool check(int x, int y){
  if(x>=0&&x<N&&y>=0&&y<N) return true;
  return false;
}

void dfs(int x,int y,int cnt){
  visit[x][y]=cnt;
  s[cnt].total+=arr[x][y];
  s[cnt].cnt++;
  for(int i=0;i<4;i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(check(nx,ny)){
      if(visit[nx][ny]==0){
        int dif = abs(arr[nx][ny]-arr[x][y]);
        if(dif>=L&&dif<=R)
          dfs(nx,ny,cnt);
      }
    }
    
  }
}

void input(){
  cin >> N >> L >> R;
  
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> arr[i][j];
    }
  }
}

bool flag=true;
int cnt;
void ck(){
  cnt=1;
  memset(visit,0,sizeof(visit));
  // visit=n s[n]~
  
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(visit[i][j]==0){
        s[cnt].total=0;
        s[cnt].cnt=0;
        dfs(i,j,cnt++);
      }
    }
  }

  flag=false;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      int pre = arr[i][j];
      arr[i][j] = s[visit[i][j]].total/s[visit[i][j]].cnt;
      if(pre!=arr[i][j])
        flag=true;
    }
  }
}

void PRINT(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout << arr[i][j];
    }
    cout << endl;
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout << visit[i][j];
    }
    cout << endl;
  }
}

void solve(){
  int ret=0;
  while(flag)
  {
    ck();
    // PRINT();
    ret++;
  }
  cout << ret-1;
}




int main() {
  
  input();
  solve();

}