#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N;
  cin >> N;
  
  vector<string> V;
  for(int i=0;i<N;i++){
    string s;
    cin >> s;
    for(int j=0;j<s.length();j++){
      if(s.at(j)=='.'){
        string s2 = s.substr(j+1,s.length()-j);
        V.push_back(s2);
      }
    }
  }

  sort(V.begin(),V.end());
  for(int i=0;i<V.size();i++){

    int cnt = 1;
    for(int j=i+1;j<V.size();j++){
      if(V[i].compare(V[j])==0){
        cnt++;
      }else{
        break;
      }
    }
    i+=cnt-1;
    cout << V[i] << " " << cnt << "\n";
  }
}