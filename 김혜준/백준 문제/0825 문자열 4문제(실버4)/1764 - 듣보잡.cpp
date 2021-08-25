#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  map<string,int> m;
  vector<string> ret;
  int N,M;
  cin >> N >> M;
  for(int i=0;i<N;i++){
    string s;
    cin >> s;
    m.insert({s,1});
  }
  for(int i=0;i<M;i++){
    string s;
    cin >> s;
    if(m.find(s)==m.end()){
      continue;
    }else{
      ret.push_back(s);
    }
  }
  sort(ret.begin(),ret.end());
  cout << ret.size() << "\n";
  for(auto w:ret){
    cout << w<< "\n";
  }
}

