#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--){
    string W;
    int K;
    cin >> W >> K;

    vector<int> idx[26];
    vector<int> ret;
    for(int i=0;i<W.length();i++){
      idx[W.at(i)-'a'].push_back(i);
    }

    for(int i=0;i<26;i++){
      if(idx[i].size()<K) continue;
      for(int start=0,end=K-1;end<idx[i].size();start++,end++){
        ret.push_back(idx[i][end]-idx[i][start]+1);
      }
      
    }

    if(ret.size()==0) cout << "-1\n";
    else{
      cout << *min_element(ret.begin(),ret.end()) << " " << *max_element(ret.begin(),ret.end()) << "\n";
    }

  }
  
  


}