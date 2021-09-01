#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


bool cmp(string s1,string s2){

  if(s1.length() != s2.length()){
    return s1.length()<s2.length();
  }else{
    // for(int i=0;i<s1.length();i++){
    //   if(s1.at(i)==s2.at(i)) continue;
    //   return s1.at(i)<s2.at(i);
    // }
    return s1<s2;
  }
  // return true;
}

int main(){
  int N;
  cin >> N;
  string s[20000];
  for(int i=0;i<N;i++){
    cin >> s[i];
  }

  sort(s,s+N,cmp);
  cout << s[0] << "\n";
  for(int i=1;i<N;i++){
    if(s[i].compare(s[i-1])==0) continue;

    cout << s[i] << "\n";
  }
  return 0;
}