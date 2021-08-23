#include <iostream>
#include <string>

using namespace std;

int main(){
  int N;
  cin >> N;
  string s;
  cin >> s;
  int ret=0;
  for(int i=0;i<N;i++){
    int r=s.at(i)-'0';
    ret+=r;
  }
  cout <<ret;
  
}