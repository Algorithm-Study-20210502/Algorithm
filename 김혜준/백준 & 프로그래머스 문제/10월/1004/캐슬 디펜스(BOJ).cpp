#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,D;
int arr[15][15];
vector<int> G;
int ans=0;
int COUNT=0;

void input(){
  cin >> N >> M >> D;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> arr[i][j];
      COUNT+=arr[i][j];
    }
  }
}

void simulate(){
  // 궁수의 위치 G
  int temp[15][15];
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      temp[i][j] = arr[i][j];
    }
  }
  // (N,G[0]) , (N,G[1]) , (N,G[2])
  bool flag = false;
  int count=0;
  int count2=0;
  while(count+count2!=COUNT){
    // cout << count + count2 << endl;

    vector<pair<int,int>> posi;
    for(int Arrow=0;Arrow<3;Arrow++){
      int dist=999;
      int x,y;
      for(int j=0;j<M;j++){
        for(int i=N-1;i>=0;i--){
          if(abs(i-N)+abs(G[Arrow]-j) > D) break;
          if(abs(i-N)+abs(G[Arrow]-j) >= dist) break;
          if(temp[i][j]==0) continue;
          // cout << Arrow << " " << i << " " << j << endl;
          dist = abs(i-N) + abs(G[Arrow]-j);
          x=i;
          y=j;
        }
        
      }
      if(dist!=999)
        posi.push_back({x,y});
    }

    for(auto w:posi){
      int x = w.first;
      int y = w.second;
      
      if(temp[x][y]==1){
        count++;
        temp[x][y]=0;
        ans=max(ans,count);
      }
    }


    for(int i=N-1;i>=0;i--){
      for(int j=0;j<M;j++){
        if(i==N-1){
          if(temp[i][j]==1){
            temp[i][j]=0;
            count2++;
          }
          temp[i][j] = temp[i-1][j];
        }else if(i!=0){
          temp[i][j] = temp[i-1][j];
        }else{
          temp[i][j]=0;
        }
      }
    }

    // for(int i=0;i<N;i++){
    //   for(int j=0;j<M;j++){
    //     cout << temp[i][j] << " ";
    //   }
    //   cout << endl;
    // }


  }

  
  

}

void solve(){

  vector<int> V,K;

  for(int i=0;i<M;i++){
    V.push_back(i);
  }
  for(int i=0;i<M-3;i++){
    K.push_back(0);
  }
  for(int i=0;i<3;i++){
    K.push_back(1);
  }

  do{
    
    G.clear();
    for(int i=0;i<M;i++){
      if(K[i]){
        G.push_back(V[i]);
        // cout << V[i] << " ";
      }
    }
    // cout << endl;
    simulate();
  }while(next_permutation(K.begin(),K.end()));

  cout << ans;
}

int main() {
  input();
  solve();
}