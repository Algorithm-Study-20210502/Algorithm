#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
  int N;
  cin >> N;
  string init;
  getline(cin,init);
  for(int i=0;i<N;i++){
    string s;
    int arr[26];
    memset(arr,0,sizeof(arr));
    
    getline(cin,s);

    for(int j=0;j<s.length();j++){
      if(s.at(j)>='a' && s.at(j)<='z'){
        arr[s.at(j)-'a']++;
      }
    }
    int l=0,num=0,idx=0;

    for(int j=0;j<26;j++){
      if(l<arr[j]){
        l=arr[j];
        idx=j;
        num=1;
      }else if(l==arr[j]){
        num++;
      }
    }

    char ret=idx+'a';
    if(num>1) cout << "?";
    else cout << ret;
    cout << "\n";
  
  }

}