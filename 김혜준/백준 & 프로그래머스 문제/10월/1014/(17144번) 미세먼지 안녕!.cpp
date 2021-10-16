#include <iostream>
#include <cstring>
using namespace std;

int R,C,T;
int arr[50][50];
int temp[50][50];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int X1=-1,X2=-1;

void PRINT(){
  cout << endl;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void input(){
  cin >> R >> C >> T;

  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cin >> arr[i][j];
      if(arr[i][j]==-1){
        if(X1==-1)
          X1=i;
        else
          X2=i;
      }
    }
  }

}

bool check(int x,int y){
  if(x>=0&&x<R&&y>=0&&y<C){
    if(arr[x][y]!=-1)
      return true;
  }
  return false;
}

void diffusion(){
  memset(temp,0,sizeof(temp));

  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(arr[i][j]>0){
        int cnt=0;
        for(int k=0;k<4;k++){
          int nx = i + dx[k];
          int ny = j + dy[k];

          if(check(nx,ny)){
            temp[nx][ny]+=arr[i][j]/5;
            cnt++;
          }

        }
        arr[i][j] -= cnt*(arr[i][j]/5);
      }
    }
  }

  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      arr[i][j]+=temp[i][j];
    }
  }
}

void airfresh(){

  arr[X1-1][0]=0;
  for(int i=X1-1;i>0;i--){
    arr[i][0] = arr[i-1][0]; 
  }
  for(int i=0;i<C-1;i++){
    arr[0][i] = arr[0][i+1];
  }
  for(int i=0;i<X1;i++){
    arr[i][C-1] = arr[i+1][C-1];
  }
  for(int i=C-1;i>=2;i--){
    arr[X1][i]=arr[X1][i-1];
  }
  arr[X1][1]=0;
  arr[X2+1][0]=0;
  
  for(int i=X2+1;i<R-1;i++){
    arr[i][0] = arr[i+1][0];
  }
  for(int i=0;i<C-1;i++){
    arr[R-1][i] = arr[R-1][i+1];
  }
  for(int i=R-1;i>X2;i--){
    arr[i][C-1] = arr[i-1][C-1];
  }
  for(int i=C-1;i>=2;i--){
    arr[X2][i] = arr[X2][i-1];
  }
  arr[X2][1]=0;
}

void solve(){
  for(int i=0;i<T;i++){
    diffusion();
    // PRINT();
    airfresh();
    // PRINT();
  }
  int ret=0;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(arr[i][j]>0)
        ret+=arr[i][j];
    }
  }
  cout << ret;
}

int main() {
  input();
  solve();
}