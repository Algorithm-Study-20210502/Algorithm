#include <iostream>

using namespace std;

int N,M;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int arr[1000][1000];

void input(){
  cin >> N >> M;
}

void solve(){
  int cnt = 1;
  int x = N/2+1;
  int y = N/2+1;
  int c=1;
  arr[x][y] = c++;
  int X,Y;
  while(1){
    for(int i=0;i<4;i++){
      for(int j=0;j<cnt;j++){
        // cout << x<< " " << y << endl;
        x=x+dx[i];
        y=y+dy[i];
        if(c==M) X=x,Y=y;
        arr[x][y]=c++;
        if(x==1&&y==1) break;
      }
      if(i==1||i==3) cnt++;
      if(x==1&&y==1) break;
    }
    if(x==1&&y==1) break;
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  if(M==1){
    X=N/2+1,Y=N/2+1;
  }
  cout << X << " " << Y;

}

int main() {
  input();
  solve();
}