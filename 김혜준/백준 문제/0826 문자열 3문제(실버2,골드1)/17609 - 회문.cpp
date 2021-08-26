#include <iostream>

using namespace std;

bool check(string s){
  // cout << s << endl;
  int len = s.length()-1;
  int left = 0;
  int right = len;
  while(left<=right){
    if(s.at(left++)==s.at(right--)){
      continue;
    }else{
      return false;
    }
  }
  return true;
}

bool check2(string s){
  // string s1,s2;

  // for(int i=0;i<s.length();i++){
  //   s1=s.substr(0,i);//0~i-1
  //   s2=s.substr(i+1,s.length()-1-i); // i+1...leng-1
  //   string s3=s1.append(s2);
  //   if(check(s3))return true;
  // }
  // return false;
  int l=0;
  int r=s.length()-1;

  while(l<=r){
    if(s.at(l)==s.at(r)){
      l++;
      r--;
      continue;
    }else{
      //l을 뺴는 경우
      if(check(s.substr(l+1,r-l))){
        return true;
      }else{
        if(check(s.substr(l,r-l))){
          return true;
        }else{
         return false;
        }
      }
      // 중간에 무언가를 뺴는 경우...?
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  string s[N];
  for(int i=0;i<N;i++){
    
    cin >> s[i];
    if(check(s[i])){
      cout << "0";
    }else if(check2(s[i])){
      cout << "1";
    }else{
      cout << "2";
    }
    cout << "\n";
  }
}