#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

void input();
void solve();
void search(int,int);
int calcDist(int,int);
bool check(int, int);

int N,sx,sy,num=0,sc=2,total=0;
int arr[20][20];
bool visit[20][20];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int main() {
  input();
  solve();
}

void input(){
  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> arr[i][j];
      if(arr[i][j]==9){
        sx=i;
        sy=j;
        arr[i][j]=0;
      }
    }
  }
}

void solve(){
  search(sx,sy);
  cout << total;
}

void search(int x,int y){
  int dist=9999;
  int nx,ny;
  bool flag=false;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(arr[i][j]<sc&&arr[i][j]>0){
        int cur_dist = calcDist(i,j);
        if(cur_dist!=-1&&cur_dist<dist){
          dist=cur_dist;
          nx=i;
          ny=j;
          flag=true;
        }
      }
    }
  }

  if(flag){
    sx=nx;
    sy=ny;
    num++;
    total+=dist;
    // cout << sx << " " << sy << " " << total<<endl;
    if(num==sc){
      sc++;
      num=0;
    }
    arr[sx][sy]=0;
    search(sx,sy);
  }else{
    return;
  }
}

int calcDist(int x,int y){
  memset(visit,false,sizeof(visit));
  queue<pair<pair<int,int>,int>> q;
  q.push({{x,y},0});
  int ret=9999;
  while(!q.empty()){
    
    int px=q.front().first.first;
    int py=q.front().first.second;
    int cnt=q.front().second;
    
    q.pop();
    // cout << px << " " << py <<endl;
    if(px==sx&&py==sy) return cnt;
    
    for(int i=0;i<4;i++){
      int nx=px+dx[i];
      int ny=py+dy[i];

      if(check(nx,ny)){
        if(arr[nx][ny]<=sc){
          if(visit[nx][ny]==false){
            visit[nx][ny]=true;
            q.push({{nx,ny},cnt+1});
          }
        }
      }
    }
  }
  return -1;
}

bool check(int x,int y){
  if(x>=0&&x<N&&y>=0&&y<N)
    return true;
  return false;
}