#include <iostream>
#include <cstring>

using namespace std;

int main(){
  int N;
  cin >> N;
  int ret=0;
  for(int i=0;i<N;i++){
    string s;
    cin >> s;
    int arr[26];
    memset(arr,0,sizeof(arr));
    bool flag=true;
    for(int i=0;i<s.length();i++){
      if(arr[s.at(i)-'a']){
        if(s.at(i-1)!=s.at(i)){
          flag=false;
          break;
        }
      }
      arr[s.at(i)-'a']++;
    }

    if(flag)
      ret++;
  }
  cout << ret;
}