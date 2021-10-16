#include <iostream>
#include <cstring>

using namespace std;
int arr[31];

int main() {
  memset(arr,0,sizeof(arr));
  for(int i=0;i<28;i++){
    int a;
    cin >> a;
    arr[a]=1;
  }
  for(int i=1;i<=30;i++){
    if(arr[i]==0){
      cout << i << "\n";
    }
  }
}