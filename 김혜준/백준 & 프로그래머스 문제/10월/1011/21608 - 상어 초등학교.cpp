#include <iostream>
#include <cstring>

using namespace std;

int arr[21][21];
int like[401][4];
int N;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int order[401];
typedef struct info{
  int num_like=0;
  int num_blank=0;
}info;

void input(){
  cin >> N;
  memset(arr,0,sizeof(arr));
  memset(like,0,sizeof(like));
  memset(order,0,sizeof(order));
  int student;
  for(int i=1;i<=N*N;i++){
    cin >> student;
    order[i]=student;
    for(int j=0;j<4;j++){
      cin >> like[student][j];
    }
  }
}

bool check2(int a,int b){
  for(int i=0;i<4;i++){
    if(a==like[b][i])
      return true;
  }
  return false;
}

bool check(int x,int y){
  if(x>=1&&x<=N&&y>=1&&y<=N)
    return true;
  return false;
}

void batch(int n){
  info visit[N+1][N+1];

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      int x=i;
      int y=j;
      for(int k=0;k<4;k++){
        int nx=x+dx[k];
        int ny=y+dy[k];

        if(check(nx,ny)){
          if(arr[nx][ny]==0){
            visit[x][y].num_blank++;
          }else{
            if(check2(arr[nx][ny],n)){
              visit[x][y].num_like++;
            }
          }
        }
      }

    }
  }

  int max_blank=-1;
  int max_like=-1;
  int max_x;
  int max_y;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(arr[i][j]!=0)
        continue;
      
      if(max_like<visit[i][j].num_like){
        max_like=visit[i][j].num_like;
        max_blank=visit[i][j].num_blank;
        max_x=i;
        max_y=j;
      }else if(max_like==visit[i][j].num_like && max_blank<visit[i][j].num_blank){
        max_like=visit[i][j].num_like;
        max_blank=visit[i][j].num_blank;
        max_x=i;
        max_y=j;
      } 
    }
  }

  arr[max_x][max_y]=n;
}

void inspect(){
  int ret=0;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      int cnt=0;
      for(int k=0;k<4;k++){
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(check(nx,ny)){
          if(check2(arr[nx][ny],arr[i][j])){
            cnt++;
          }
        }
      }
      switch(cnt){
        case 0:
          ret+=0;
          break;
        case 1:
          ret+=1;
          break;
        case 2:
          ret+=10;
          break;
        case 3:
          ret+=100;
          break;
        case 4:
          ret+=1000;
          break;
      }
    }
  }
  cout << ret;
}

void solve(){
  for(int i=1;i<=N*N;i++){
    batch(order[i]);
  }
  inspect();
}



int main() {
  input();
  solve();
  cout << endl;
  // for(int i=1;i<=N;i++){
  //   for(int j=1;j<=N;j++){
  //     cout << arr[i][j];
  //   }
  //   cout << endl;
  // }
}