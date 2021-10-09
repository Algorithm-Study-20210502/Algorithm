#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101][101];
int visit[101];
int r,c,k;
bool cmp(pair<int,int> a, pair<int,int> b){
  if(a.second==b.second){
    return a.first < b.first;
  }else{
    return a.second < b.second;
  }
}

void input(){
  cin >> r >> c >> k;
  for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
      cin >> arr[i][j];
    }
  }
}
void solve(){
  int ans=-1;
  int R=3,C=3;
  while(1){
    
    ans++;
    if(ans==101){
      break;
    }
    if(arr[r][c]==k){
      break;
    }
    // cout << R << " " << C << endl;
    if(R>=C){
      int R2=0;
      for(int i=1;i<=R;i++){
        int M=0;
        vector<pair<int,int>> V;
        memset(visit,0,sizeof(visit));
        for(int j=1;j<=C;j++){
          if(arr[i][j]==0)continue;
          visit[arr[i][j]]++;
          M=max(arr[i][j],M);
        }
        // cout << M << endl;
        for(int j=1;j<=M;j++){
          if(visit[j]==0) continue;
          V.push_back({j,visit[j]});
        }
        sort(V.begin(),V.end(),cmp);
        int t = 1;
        for(int j=0;j<V.size();j++){
          int a=V[j].first;
          int b=V[j].second;
          if(t>100) break;
          arr[i][t++]=a;
          if(t>100) break;
          arr[i][t++]=b;
          if(t>100) break;
        }
        R2=max(R2,t-1);
        for(int j=t;j<=100;j++){
          arr[i][j]=0;
        }
      }
      C=R2;
    }else{
      // cout << "!!!" << endl;
      int C2=0;
      for(int i=1;i<=C;i++){
        int M=0;
        vector<pair<int,int>> V;
        memset(visit,0,sizeof(visit));
        for(int j=1;j<=R;j++){
          if(arr[j][i]==0)continue;
          visit[arr[j][i]]++;
          M=max(arr[j][i],M);
        }
        // cout << i << " " << R<<' ' << M << " ";
        for(int j=1;j<=M;j++){
          if(visit[j]==0) continue;
          V.push_back({j,visit[j]});
          // cout << j << " " << visit[j] << ' ';
        }
        // cout << endl;
        sort(V.begin(),V.end(),cmp);
        int t = 1;

        for(int j=0;j<V.size();j++){
          int a=V[j].first;
          int b=V[j].second;
          if(t>100) break;
          arr[t++][i]=a;
          if(t>100) break;
          arr[t++][i]=b;
          if(t>100) break;
        }
        C2=max(C2,t-1);
        for(int j=t;j<=100;j++){
          arr[j][i]=0;
        }
      }
      R=C2;
      
    }
    // if(ans>3) continue;

    // cout << endl;
    // for(int i=1;i<=R;i++){
    //   for(int j=1;j<=C;j++){
    //     cout << arr[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
  }

  
  if(ans>100) cout << -1;
  else cout << ans;
}

int main() {
  input();
  solve();
}