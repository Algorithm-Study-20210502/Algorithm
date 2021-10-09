#include <iostream>

using namespace std;

int r1,r2,c1,c2;

int arr[51][5];
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};

int check(int m){
  int t=0;
  while(m!=0){
    m/=10;
    t++;
  }
  return t;
}

int main() {
  cin >> r1 >> c1 >> r2 >> c2;
  // -5000->1
  // 0->5001
  // 5000->10001
  int x=5001,y=5001;
  
  int cnt=1;
  int num=1;
  // arr[x][y]=cnt++;
  int M=0;
  if(r1+5001<=x&&r2+5001>=x && c1+5001<=y && c2+5001>=y){
    arr[x-r1-5001][y-c1-5001]=cnt;
    M=max(M,cnt);
  } 
  cnt++;
  
  while(1){
    for(int i=0;i<4;i++){
      for(int j=0;j<num;j++){
        x+=dx[i];
        y+=dy[i];
        if(x<1||x>10001||y<1||y>10001) break;
        if(r1+5001<=x&&r2+5001>=x && c1+5001<=y && c2+5001>=y){
          arr[x-r1-5001][y-c1-5001]=cnt;
          M=max(M,cnt);
        }
        cnt++;
        if(x<1||x>10001||y<1||y>10001) break;
      }
      if(i==1||i==3){
        num++;
      }
      if(x<1||x>10001||y<1||y>10001) break;
    }
    if(x<1||x>10001||y<1||y>10001) break;
  }
  int l=check(M);  

  for(int i=0;i<=r2-r1;i++){
    for(int j=0;j<=c2-c1;j++){
      int cur = check(arr[i][j]);
      for(int k=0;k<l-cur;k++){
        cout << ' ';
      }
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}