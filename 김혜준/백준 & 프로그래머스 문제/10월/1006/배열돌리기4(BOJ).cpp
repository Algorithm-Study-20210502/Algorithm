#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,K;
int arr[51][51];
int temp[51][51];

typedef struct info{
  int r,c,s;
}info;

vector <info> F;

void PRINT(){
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  
  cin >> N >> M >> K;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      cin >> arr[i][j];
    }
  }

  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      temp[i][j]=arr[i][j];
    }
  }

  for(int i=0;i<K;i++){
    int r,c,s;
    cin >> r >> c >> s;
    info f;
    f.r=r;
    f.c=c;
    f.s=s;
    F.push_back(f);
  }

  vector<int>V;
  int size = F.size();
  for(int i=0;i<size;i++){
    V.push_back(i);
  }
  int ans=999999999;
  
  do{
    
    for(int i=1;i<=N;i++){
      for(int j=1;j<=M;j++){
        arr[i][j]=temp[i][j];
      }
    }
    

    for(int i=0;i<size;i++){
      int idx = V[i];

      info w =  F[idx];

      int r = w.r;
      int c = w.c;
      int s = w.s;

      int sx = r-s;
      int sy = c-s;

      int ex = r+s;
      int ey = c+s;

      bool visit[51][51]={false,};
      // cout << sx << " " << sy << endl;
      // cout << ex << " " << ey << endl;
      for(int x=sx,y=sy;visit[x][y]==false;x++,y++){
        // cout << x << " " << y << endl;
        int temp = arr[x][y];
        int cx = x;
        int cy = y;
        int nx = x+1;
        int ny = y;
        while(nx<=ex&&visit[nx][ny]==false){
          // cout << cx << " " << cy << endl;
          // cout << nx << " " << ny << endl;
          visit[cx][cy]=true;
          arr[cx][cy] = arr[nx][ny];
          cx++;
          nx++;
        }
        // cout << endl;
        nx--;
        ny++;

        while(ny<=ey&&visit[nx][ny]==false){
          visit[cx][cy]=true;
          arr[cx][cy] = arr[nx][ny];
          cy++;
          ny++;
        }
        ny--;
        nx--;

        while(nx>=sx&&visit[nx][ny]==false){
          visit[cx][cy]=true;
          arr[cx][cy] = arr[nx][ny];
          cx--;
          nx--;
        }
        nx++;
        ny--;

        while(ny>=sy&&visit[nx][ny]==false){
          // cout << cx << " " << cy << endl;
          // cout << nx << " " << ny << endl;
          visit[cx][cy]=true;
          arr[cx][cy]=arr[nx][ny];
          cy--;
          ny--;
        }
        ny++;
        
        arr[cx][cy]=temp;
        visit[cx][cy]=true;
        
      }

    }
    for(int i=1;i<=N;i++){
      int total=0;
      for(int j=1;j<=M;j++){
        total+=arr[i][j];
      }
      ans = min(ans,total);
    }
    // PRINT();

  }while(next_permutation(V.begin(),V.end()));


  for(auto w: F){
    
    
  }
  

  
  cout << ans;


}