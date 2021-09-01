#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  string s2;
  cin >> s2;

  // string s3="";
  // for(int i=0;i<s.length();i++){
  //   if(s.at(i)>='0' && s.at(i)<='9') continue;
  //   s3.push_back(s.at(i));
  // }

  // for(int i=0;i<s3.length();i++){
  //   if(s3.at(i)==s2.at(0)){
  //     int idx=1;
  //     for(int j=i+1;j<s3.length();j++){
  //       if(s3.at(j)==)
  //     }
  //   }else{
  //     continue;
  //   }
    
  // }

  int idx=0;
  for(int i=0;i<s.length();i++){
    
    if(s.at(i)>='0'&&s.at(i)<='9')
      continue;

    if(s.at(i)==s2.at(0)){
      
      if(s2.length()==1){
        cout << 1;
        return 0;
      }

      int idx=1;

      for(int j=i+1;j<s.length();j++){
        if(s.at(j)>='0' && s.at(j)<='9')
          continue;
        
        if(s.at(j)==s2.at(idx)){
          idx+=1;
          if(idx==s2.length()){
            cout << 1;
            return 0;
          }

        }else{
          break;
        }

      }
    }
  }
  
  cout << 0;
}