#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<int> V;

struct cmp{
  bool operator()(int a,int b){
    return a>b;
  }
};

priority_queue<int, vector<int>,cmp> pq;

void input(){
  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      int a;
      // cin >> a;
      scanf("%d",&a);
      // V.push_back(a);
      if(pq.size()<N){
        pq.push(a);
      }else{
        if(pq.top()<a){
          pq.pop();
          pq.push(a);
        }
      } 
    }
  }
}

void solve(){
  // sort(V.begin(),V.end());
  // printf("%d",V[N*N-N]);

  // for(int i=0;i<N-1;i++){
  //   cout << pq.top();
  //   pq.pop();
  // }
  cout << pq.top();
}

int main() {
  input();
  solve();
}