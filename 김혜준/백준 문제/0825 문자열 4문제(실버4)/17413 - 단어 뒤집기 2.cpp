#include <iostream>

using namespace std;

void reverse_print(string s){
  for(int i=s.length()-1;i>=0;i--){
    cout << s.at(i);
  }
}

int main() {
  string s;
  getline(cin,s);
  
  string s1;
  bool flag=false;
  for(int i=0;i<s.length();i++){

    /*
      <를 만나면 >까지 쭉 출력
      
      문자열 만나면 모았다가
      <나 공백을 만나면 뒤집어 출력
    */
    if(flag){
      cout << s.at(i);
      if(s.at(i)=='>'){
        flag=false;
      }
      continue;
    }

    if((s.at(i)>='a'&&s.at(i)<='z')||(s.at(i)>='0'&&s.at(i)<='9'))
      s1.push_back(s.at(i));

    if(s.at(i)=='<'){
      reverse_print(s1);
      cout << "<";
      s1="";
      flag=true;
    }
    if(s.at(i)==' '){
      reverse_print(s1);
      cout << " ";
      s1="";
    }
    

  }
  reverse_print(s1);
  
}