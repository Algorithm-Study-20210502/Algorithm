#include <iostream>
#include <algorithm>

using namespace std;

int cmp2(string s1,string s2){
  int idx1=0,idx2=0;
  int zero1=0,zero2=0;
  for(int i=0;i<s1.length();i++){
    if(s1.at(i)=='0'){
      idx1=i+1;
      zero1++;
    }else{
      break;
    }
  }
  for(int i=0;i<s2.length();i++){
    if(s2.at(i)=='0'){
      idx2=i+1;
      zero2++;
    }else{
      break;
    }
  }
  if( (s1.length()-idx1) == (s2.length()-idx2)){
    for(int i1=idx1, i2=idx2;i1<s1.length();i1++,i2++){
      if(s1.at(i1)==s2.at(i2)){
        continue;
      }else{
        return s1.at(i1)<s2.at(i2);
      }
    }
    if(zero1==zero2)
      return -1555;
    else
      return zero1<zero2;
  }else{
    return (s1.length()-idx1) < (s2.length()-idx2);
  }
}

bool cmp(string s1,string s2){
  int len = min(s1.length(),s2.length());
  for(int i=0;i<len;i++){
    char c1 = s1.at(i);
    char c2 = s2.at(i);

    long long l1=-1,l2=-1;
    int zero1=0,zero2=0;
    int zari=0;

    string s11,s21;
    if(c1>='0'&&c1<='9'){
      l1=0;
      if(c2<'0'||c2>'9'){
        return true; // s1은 숫자 s2는 문자
      }
      for(int j=i;j<s1.length();j++){
        if(s1.at(j)>='0'&&s1.at(j)<='9'){
          s11.push_back(s1.at(j));
        }else{
          break;
        }
      }
    }

    if(c2>='0'&&c2<='9'){
      l2=0;
      if(c1<'0'||c1>'9'){
        return false;
      }
      
      for(int j=i;j<s2.length();j++){

        if(s2.at(j)>='0'&&s2.at(j)<='9'){
          s21.push_back(s2.at(j));
        }else{
          break;
        }
      }
      // l2 = stol(s21);
    }
    // cout << l1 << " " << l2 << endl;

    
    if(l1==-1){ // 둘다 문자
      if(c1==c2)continue;
      if(c1>='a'&&c1<='z'){
        if(c2>='a'&&c2<='z'){ // 둘다 소문자
          return c1<c2;
        }else{ // s1 소문자 s2대문자
          c2-=('A'-'a');
          if(c1==c2) return false;
          else return c1<c2;
        }
      }else{
        
        if(c2>='a'&&c2<='z') // 대문자 소문자
        {
          c1-=('A'-'a');
          if(c1==c2) return true;
          else return c1<c2;
        }else{ //대문자 대문자
          if(c1==c2) continue;
          else return c1<c2; 
        }
      }
    }else{ // 둘다 숫자
      int k=cmp2(s11,s21);
      if(k!=-1555) return k;
      else{
        i+=s11.length()-1;
      }
    }


  }
  return s1.length()<s2.length();
}

int main() {
  int N;
  cin >> N;
  string arr[N];
  for(int i=0;i<N;i++){
    cin >> arr[i];
  }
  sort(arr,arr+N,cmp);
  for(int i=0;i<N;i++){
    cout << arr[i] << "\n"; 
  }
}