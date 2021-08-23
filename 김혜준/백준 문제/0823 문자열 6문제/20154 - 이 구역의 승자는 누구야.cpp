#include <iostream>

using namespace std;

int main() {
  int arr[26];
  arr[0]=3;
  arr[1]=2;
  arr[2]=1;
  arr[3]=2;
  arr[4]=3;
  arr[5]=3;
  arr[6]=3;
  arr[7]=3;
  arr[8]=1;
  arr[9]=1;
  arr[10]=3;
  arr[11]=1;
  arr[12]=3;
  arr[13]=3;
  arr[14]=1;
  arr[15]=2;
  arr[16]=2;
  arr[17]=2;
  arr[18]=1;
  arr[19]=2;
  arr[20]=1;
  arr[21]=1;
  arr[22]=2;
  arr[23]=2;
  arr[24]=2;
  arr[25]=1;
  string S;
  cin >> S;
  
  int ret=0;
  for(int i=0;i<S.length();i++){
    ret+=arr[S.at(i)-'A'];
  }
  if(ret%2==1)
    cout << "I'm a winner!";
  else
    cout << "You're the winner?";
  
}