#include <iostream>

using namespace std;

bool check(int n){
  if(n%4==0){
    if(n%100!=0 || n%400==0){
      return true;
    }
  }
  return false;
}

int main() {
  int N;
  cin >> N;

  if(check(N)){
    cout << 1;
  }else{
    cout << 0;
  }

}