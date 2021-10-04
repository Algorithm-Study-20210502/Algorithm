#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool check(string s){
    stack<char> st;
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='{' || s[i]=='(' || s[i]=='['){
            st.push(s[i]);
        }else{
            if(st.empty()) return false;
            char c1 = st.top();
            char c2 = s[i];
            // cout << c1 << c2 << endl;
            if(abs(c2-c1)>2){
                // cout << "F" << endl;
                return false;
            }else{
                st.pop();
            }
        }
    }
    if(st.empty()) return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    
    
    for(int i=0;i<s.length();i++){
        string temp="";
        temp+=s.substr(i);
        temp+=s.substr(0,i);
        
        if(check(temp)){
            answer++;
        }
    }
    
    return answer;
}