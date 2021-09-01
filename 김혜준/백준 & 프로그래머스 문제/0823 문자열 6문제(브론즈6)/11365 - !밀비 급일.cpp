#include <iostream>
#include <string>

using namespace std;

int main(){
  string s; 
  
  string end = "END";
  while(getline(cin,s)){
    if(s.compare(end)==0){
      break;
    }else{
      
      for(int i=s.length()-1;i>=0;i--){
        cout << s.at(i);
      }
      cout << "\n";
    }
  }
  
}