#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  string s,t;
  while(cin >> s >> t){
    int cnt=0;
    for(int i=0;i<t.length();i++){
      if(t.at(i)==s.at(cnt)){
        cnt++;
        if(cnt==s.length())
          break;
      }
    }
    if(cnt==s.length())
      cout << "Yes\n";
    else
      cout << "No\n";
    
  }
}