#include <iostream>
#include <vector>

using namespace std;

int N,M,K;
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
int num=0;
typedef struct fireBall{
  int x;
  int y;
  int m;
  int dir;
  int speed;
  bool live=true;
}FB;

vector<FB> arr[50][50];
vector<FB> fbV;

void input(){
  cin >> N >> M >> K;
  num=M;
  for(int i=0;i<M;i++){
    int r,c,m,s,d;
    cin >> r >> c >> m >> s >> d;
    r-=1;
    c-=1;
    FB f;
    f.x=r;
    f.y=c;
    f.m=m;
    f.dir=d;
    f.speed=s;
    fbV.push_back(f);
    arr[r][c].push_back(f);
  }
}

bool check(int x,int y){
  if(x>=0&&x<N&&y>=0&&y<N)
    return true;
  return false;
}

void move(){

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      arr[i][j].clear();
    }
  }

  for(int i=0;i<fbV.size();i++){
    FB cur = fbV[i];

    int x = cur.x;
    int y = cur.y;
    int dir = cur.dir;
    int sp = cur.speed;
    
    int nx = x+dx[dir]*sp;
    int ny = y+dy[dir]*sp;

    while(nx<0){
      nx+=N;
    }
    while(ny<0){
      ny+=N;
    }
    nx%=N;
    ny%=N;

    cur.x=nx;
    cur.y=ny;

    arr[nx][ny].push_back(cur);
  }
}

void sum(){

  vector<FB> temp;

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(arr[i][j].size()==0) continue;
      else if(arr[i][j].size()==1) temp.push_back(arr[i][j][0]);
      else{

        int m=0,s=0,odd=0,even=0;

        for(int k=0;k<arr[i][j].size();k++){
          FB cur = arr[i][j][k];
          
          m+=cur.m;
          s+=cur.speed;
          if(cur.dir%2==1) odd++;
          else even++;
        }
        m/=5;
        if(m==0) continue;
        s/=arr[i][j].size();
        if(odd==0||even==0){
          for(int q=0;q<4;q++){
            temp.push_back({i,j,m,2*q,s});
          }
        }else{
          for(int q=0;q<4;q++){
            temp.push_back({i,j,m,2*q+1,s});
          }
        }
      }
    }
  }
  fbV=temp;
}


void solve(){
  for(int i=0;i<K;i++){
    move();
    sum();
  }
  int ret=0;
  for(auto w:fbV){
    ret+=w.m;
  }
  cout << ret;
}

int main() {
  input();
  solve();
}