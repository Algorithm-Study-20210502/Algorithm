#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int ret = s.length();
    for(int i=1;i<=s.length()/2;i++){
        // cout << "@" << i << "@" << endl;
        int len=0;        
        int conti=0;
        len+=i;
        int idx=0;
        bool flag=false;
        int conti2=0;
        for(int start=0;start+i+i-1<s.length();start+=i){
            len+=i;
            idx=start;
            // cout << s.substr(start,i) << " " << s.substr(start+i,i) << endl;
            if(s.substr(start,i)==s.substr(start+i,i)){
                flag=true;
                conti++;
                conti2++;
                if(conti2==1||conti2==9||conti2==99){
                    len++;
                }
            }else{
                conti2=0;
            }
        }
        // cout << idx << endl;
        len += s.length()-(idx+2*i);
        len-=i*conti;
        // cout << len << endl;
        ret=min(len,ret);
    }
    return ret;
}