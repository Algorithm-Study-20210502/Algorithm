#include <iostream>

using namespace std;

int N;
int arr[21][21];
int total=0;

void input(){
  cin >> N;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cin >> arr[i][j];
      total+=arr[i][j];
    }
  }
}

void solve(){
  
  /*
    x>=1,x+d1+d2<=N
    1<=y-d1<y<y+d2<=N

  */
  int ans=99999;

  for(int x=1;x<N;x++){
    for(int y=2;y<N;y++){
      for(int d1=1;d1<N;d1++){
        if(y-d1<1) break;        
        for(int d2=1;d2<N;d2++){
          if(x+d1+d2>N) break;
          if(N<y+d2) break;
          int MIN=999999,MAX=-1;
          int total1=0,total2=0,total3=0,total4=0,total5=0;

          for(int i=1;i<x+d1;i++){
            for(int j=1;j<=y;j++){
              if(i+j>=x+y) continue;
              // if(x==3&&y==5&&d1==2&&d2==1) cout << i << " " << j << endl;
              total1+=arr[i][j];
            }
          }
          // if(x==3&&y==5&&d1==2&&d2==1)
          //   cout << endl;
          for(int i=1;i<=x+d2;i++){
            for(int j=y+1;j<=N;j++){
              if(i-x>=j-y)
                continue;
              // if(x==3&&y==5&&d1==2&&d2==1) cout << i << " " << j << endl;
              total2+=arr[i][j];
            }
          }
          // if(x==3&&y==5&&d1==2&&d2==1)
          //   cout << endl;
          int cnt,cnt2;
          // x+1,1<=~<x+1,y-1
          cnt=y+d2-d1-(d2+1);
          for(int i=x+d1;i<=N;i++){
            cnt2=cnt++;
            for(int j=1;j<y-d1+d2;j++){
              if(cnt2--==0)break;
              // if(x==3&&y==5&&d1==2&&d2==1) cout << i << " " << j << endl;
              total3+=arr[i][j];
            }
          }
          // if(x==3&&y==5&&d1==2&&d2==1)
          //   cout << endl;

          cnt=d1;
          for(int i=x+d2+1;i<=N;i++){
            cnt2=cnt--;
            for(int j=y-d1+d2;j<=N;j++){
              if(cnt2-->0)continue;
              // if(x==3&&y==5&&d1==2&&d2==1) cout << i << " " << j << endl;
              total4+=arr[i][j];
            }
          }
          // if(x==3&&y==5&&d1==2&&d2==1)
          //   cout << endl;
          
          total5=total-total1-total2-total3-total4;
          MAX=max(MAX,total1);
          MAX=max(MAX,total2);
          MAX=max(MAX,total3);
          MAX=max(MAX,total4);
          MAX=max(MAX,total5);

          MIN=min(MIN,total1);
          MIN=min(MIN,total2);
          MIN=min(MIN,total3);
          MIN=min(MIN,total4);
          MIN=min(MIN,total5);
          // if(x==3&&y==5&&d1==2&&d2==1) cout << total1 <<" " <<total2 << " " << total3 <<" " <<total4<< " " << total5 << endl;

          ans = min(ans,MAX-MIN);

        }
      }
    }
  }
  cout << ans;


}

int main() {
  input();
  solve();
}