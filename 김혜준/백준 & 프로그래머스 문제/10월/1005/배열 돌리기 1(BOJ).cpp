#include <iostream>
#include <cstring>

using namespace std;

int N,M,R;
int arr[300][300];
bool visit[300][300];

void input(){
  cin >> N >> M >> R;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> arr[i][j];
    }
  }
}

void PRINT(){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void rotate(){
  memset(visit,false,sizeof(visit));
  for(int i=0;i<min(N,M);i++){
    int x=i,y=i;
    int x2=i+1,y2=i;
    if(visit[x][y])break;
    visit[x][y]=true;
    int temp = arr[x][y];

    for(int j=i+1;j<M;j++){
      if(visit[x][j])break;
      visit[x][j]=true;
      y=j;
      arr[x][j-1] = arr[x][j]; 
    }
    for(int j=i+1;j<N;j++){
      if(visit[j][y])break;
      visit[j][y]=true;
      x=j;
      arr[j-1][y] = arr[j][y];
    }

    for(int j=y;j>=1;j--){
      if(visit[x][j-1])break;
      visit[x][j-1]=true;
      y=j-1;
      arr[x][j] = arr[x][j-1];
    }

    for(int j=x-1;j>=1;j--){
      if(visit[j][y])break;
      visit[j][y]=true;
      x=j;
      arr[j+1][y] = arr[j][y];
    }
    arr[x2][y2]=temp;
    // PRINT();
    // cout << endl;
  }
  
}



void solve(){
  for(int i=0;i<R;i++){
    rotate();
    // PRINT();
  }
  PRINT();
}

int main() {
  input();
  solve();
}