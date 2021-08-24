#include <iostream>
#include <string>

using namespace std;

int main() {
  string cur,next;
  cin >> cur;
  cin >> next;
  int cur_h,cur_m,cur_s;
  int next_h,next_m,next_s;

  cur_h = stoi(cur.substr(0,2));
  cur_m = stoi(cur.substr(3,2));
  cur_s = stoi(cur.substr(6,2));

  next_h = stoi(next.substr(0,2));
  next_m = stoi(next.substr(3,2));
  next_s = stoi(next.substr(6,2));

  // cout << cur_h << " " << cur_m << " " << cur_s << endl;
  
  int ret_h,ret_m,ret_s;

  if(next_h<cur_h){
    next_h+=24;
  }

  ret_h = next_h-cur_h;
  ret_m = next_m-cur_m;
  ret_s = next_s-cur_s;

  if(ret_s<0){
    ret_s+=60;
    ret_m-=1;
  }

  if(ret_m<0){
    ret_m+=60;
    ret_h-=1;
  }

  if(ret_h<0){
    ret_h+=24;
  }

  if(ret_h==0&&ret_m==0&&ret_s==0){
    cout << "24:00:00";
    return 0;
  }

  if(ret_h<10)
    cout << 0;
  cout << ret_h << ":";
  if(ret_m<10)
    cout << 0;
  cout << ret_m << ":";
  if(ret_s<10)
    cout << 0;
  cout << ret_s;


  // if(cur_h<next_h){
  //   ret_h = next_h-cur_h;

  //   if(cur_m<next_m){
  //     ret_m = next_m - cur_m;
    
  //     if(cur_s<=next_s){
  //       ret_s = next_s - cur_s;
  //     }else{
  //       ret_s = (next_s+60) - cur_s;
  //       ret_m -=1;
  //       if(ret_m<0){
  //         ret_m+=60;
  //         ret_h-=1;
  //       }
  //     }
  //   }else{

  //   }


  // }

}