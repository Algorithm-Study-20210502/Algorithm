#include <iostream>

using namespace std;

int main() {
  string s8;
  cin >> s8;
  string s2="";
  for(int i=0;i<s8.length();i++){
    switch(s8.at(i)){
      case '7':
        s2.append("111");
        break;
      case '6':
        s2.append("110");
        break;
      case '5':
        s2.append("101");
        break;
      case '4':
        s2.append("100");
        break;
      case '3':
        s2.append("011");
        break;
      case '2':
        s2.append("010");
        break;
      case '1':
        s2.append("001");
        break;
      case '0':
        s2.append("000");
        break;      
    }
    
  }

  for(int i=0;i<s2.length();i++){
    if(s2.at(0)=='0'){
      s2=s2.substr(1);
    }else{
      break;
    }
  }

  cout << s2;
}