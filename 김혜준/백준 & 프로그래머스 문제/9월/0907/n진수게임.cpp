#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int func(int n,int num){
    if(num==0) return 1;
    int cnt=0;
    while(num!=0){
        num/=n;
        cnt++;
    }
    return cnt;
}

string func2(int n,int num){
    if(num==0){
        return "0";
    }
    string s1;
    while(num!=0){
        if(num%n>=10){
            switch(num%n){
                case 10:
                    s1.push_back('A');
                    break;
                case 11:
                    s1.push_back('B');
                    break;
                case 12:
                    s1.push_back('C');
                    break;
                case 13:
                    s1.push_back('D');
                    break;
                case 14:
                    s1.push_back('E');
                    break;
                case 15:
                    s1.push_back('F');
                    break;
            }
        }else{
            s1.push_back(num%n+'0');
        }
        num/=n;
    }
    reverse(s1.begin(),s1.end());
    return s1;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int cnt=0;
    int total=0;
    while(cnt<t){
        int a=func(n,total);
        if(p<=a){
            string s;
            s = func2(n,total);
            for(int i=0;i<s.length();i++){
                p--;
                if(p==0){
                    answer.push_back(s.at(i));
                    p+=m;
                    cnt++;
                    if(cnt==t){
                        return answer;
                    }
                }
            }
        }else{
            p-=a;
        }
        total++;
        
        
    }
    
    return answer;
}