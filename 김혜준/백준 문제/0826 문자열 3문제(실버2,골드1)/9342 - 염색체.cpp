#include <iostream>
#include <regex>

using namespace std;

int main() {
  int T;
  cin >> T;
  while(T--){
    string s;
    cin >> s;
    regex r(R"(^[A-F]?A+F+C+[A-F]?$)");
    if(regex_match(s,r)){
      cout << "Infected!\n";
    }else{
      cout << "Good\n";
    }
  }
}