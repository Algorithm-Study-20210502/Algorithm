#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool check(string p){
    int a1=0,a2=0;
    
    for(auto w:p){
        if(w=='('){
            a1++;
        }else{
            a2++;
        }
        if(a2>a1){
            return false;
        }
    }
    return true;
}

string solution(string p) {
    if(check(p))return p;
    string answer = "";
    if(p.length()!=0){
        string u="",v="";
        int a1=0,a2=0;
        int idx=-1;
        for(int i=0;i<p.length();i++){
            if(p.at(i)=='('){
                a1++;
            }else{
                a2++;
            }
            u.push_back(p.at(i));
            if(a1==a2)
            {
                idx=i+1;
                break;
            }
        }
        v=p.substr(idx);
        cout << u << " " << v << endl; 
        if(check(u)){
            return u.append(solution(v));
        }else{
            string temp ="";
            temp.push_back('(');
            temp.append(solution(v));
            temp.push_back(')');
            u=u.substr(1);
            u=u.substr(0,u.length()-1);
            for(int i=0;i<u.length();i++){
                if(u.at(i)=='(') u.at(i)=')';
                else u.at(i)='(';
            }
            temp.append(u);
            return temp;
        }
    }
    return answer;
}