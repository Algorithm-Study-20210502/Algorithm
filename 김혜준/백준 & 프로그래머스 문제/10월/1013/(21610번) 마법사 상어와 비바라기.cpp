#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct Move{
  int dir;
  int speed;
}Move;

vector<pair<int,int>> cloud;

int dx[8]={0,-1,-1,-1,0,1,1,1};
int dy[8]={-1,-1,0,1,1,1,0,-1};

int Dx[4] = {-1,-1,1,1};
int Dy[4] = {-1,1,-1,1};

int A[51][51];
Move m[100];

int N,M;

// void PRINT(){
//   for(int i=1;i<=N;i++){
//     for(int j=1;j<=N;j++){
//       cout << A[i][j] << " ";
//     }
//     cout << endl;
//   }
//   cout << endl;
// }


bool check(int x,int y){
  if(x>=1&&x<=N&&y>=1&&y<=N)
    return true;
  return false;
}

void input(){
  cin >> N >> M;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cin >> A[i][j];
    }
  }

  for(int i=0;i<M;i++){
    cin >> m[i].dir >> m[i].speed;
    m[i].dir--;
  }
}

void vivalagi(int n){
  // PRINT();
  bool visit[51][51];
  memset(visit,false,sizeof(visit));

  vector<pair<int,int>> next_cloud;

  for(int i=0;i<cloud.size();i++){
    int x = cloud[i].first;
    int y = cloud[i].second;

    int nx = x+ dx[m[n].dir]*m[n].speed;
    int ny = y+ dy[m[n].dir]*m[n].speed;

    if(!check(nx,ny)){
      while(nx<=0) nx+=N;
      while(ny<=0) ny+=N;
      while(nx>N) nx-=N;
      while(ny>N) ny-=N;
    }
    // cout << nx << " " << ny << endl;
    next_cloud.push_back({nx,ny});
    A[nx][ny]++;
  }
  // PRINT();
  cloud.clear();

  vector<int> copy;
  for(int i=0;i<next_cloud.size();i++){
    int x = next_cloud[i].first;
    int y = next_cloud[i].second;
    visit[x][y]=true;
    int plus=0;
    for(int j=0;j<4;j++){
      int nx = x + Dx[j];
      int ny = y + Dy[j];

      if(check(nx,ny)){
        if(A[nx][ny])
          A[x][y]++;
      }
    }
    copy.push_back(plus);
  }

  // for(int i=0;i<next_cloud.size();i++){
  //   int x = next_cloud[i].first;
  //   int y = next_cloud[i].second;
  //   A[x][y]+=copy[i];
  // }
  // PRINT();
  

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(A[i][j]>=2&&visit[i][j]==false){
        cloud.push_back({i,j});
        A[i][j]-=2;
      }
    }
  }  
  // cout << endl;
}

void solve(){
  int cloudX[4]={N,N,N-1,N-1};
  int cloudY[4]={1,2,1,2};
  for(int i=0;i<4;i++){
    cloud.push_back({cloudX[i],cloudY[i]});
  }

  for(int n=0;n<M;n++){
    vivalagi(n);
  }
  int ret=0;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      ret+=A[i][j];
    }
  }
  
  // cout << endl;
  cout << ret;
}

int main() {
  input();
  solve();
}