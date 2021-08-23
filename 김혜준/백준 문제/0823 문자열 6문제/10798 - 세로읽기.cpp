#include <iostream>
// #include <string>
// #include <cstring>

using namespace std;

int main(){
  string s[5];
  int l=0;
  for(int i=0;i<5;i++){
    cin >> s[i];
  }

  for(int i=0;i<15;i++){
    for(int j=0;j<5;j++){
      if(s[j].length()-1>=i){
        cout << s[j].at(i);
      }
    }
  }

  
}