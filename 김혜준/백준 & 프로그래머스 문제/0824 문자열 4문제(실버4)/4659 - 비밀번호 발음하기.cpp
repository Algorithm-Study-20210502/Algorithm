#include <iostream>

using namespace std;

bool check(string s){
  int mo=0,ja=0;
  int total_mo=0;

  for(int i=0;i<s.length();i++){
    if(i>=1){
      if(s.at(i-1)==s.at(i)){
        if(s.at(i)!='e'&&s.at(i)!='o')
          return false;
      }
    }

    if(s.at(i)=='a'||s.at(i)=='e'||s.at(i)=='i'||s.at(i)=='o'||s.at(i)=='u'){
      mo++;
      if(mo==3) return false;
      ja=0;
      total_mo++;
    }else{
      ja++;
      if(ja==3) return false;
      mo=0;
    }
  }
  if(total_mo==0) return false;
  return true;
}

void solve(string s){
  if(check(s)){
    cout << "<" << s << "> is acceptable.\n"; 
  }else{
    cout << "<" << s << "> is not acceptable.\n";
  }
}

int main(){
  
  while(1){
    string s;
    cin >> s;
    if(s.compare("end")==0) break;
    solve(s);
  }
}