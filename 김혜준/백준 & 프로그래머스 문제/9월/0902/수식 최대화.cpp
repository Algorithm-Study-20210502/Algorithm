#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<char> V;

bool isNumber(char c){
    if(c>='0'&&c<='9')
        return true;
    return false;
}

long long calc(string s1, string s2, char c){
    long long a = stol(s1);
    long long b = stol(s2);
    long long total=0;
    switch(c){
        case '+':
            total=a+b;
            break;
        case '-':
            total=a-b;
            break;
        case '*':
            total=a*b;
            break;
    }
    return total;
}

long long func(string s){
    for(int k=0;k<3;k++){
        char c = V[k];
        string temp="";
        for(int i=0;i<s.length();i++){
            if(isNumber(s[i])|| temp==""){
                temp.push_back(s[i]);
            }else{
                if(s[i]==c){
                    int idx1 = i-temp.length()-1;
                    int idx2;
                    string temp2="";
                    for(int j=i+1;j<s.length();j++){
                        if(isNumber(s[j]) || temp2==""){
                            temp2.push_back(s[j]);
                            idx2=j;
                        }else{
                            break;
                        }
                    }
                    long long result = calc(temp,temp2,c);
                    
                    string s1 = "";
                    string s2 = "";
                    
                    if(idx1>=0)
                        s1 = s.substr(0,idx1+1);
                    if(idx2+1<s.length())
                        s2 = s.substr(idx2+1);
                    
                    i = s1.length()-1;
                    string s3 = s1.append(to_string(result));
                    s = s3.append(s2);
                }
                temp="";
            }
        }
        
    }
    return abs(stol(s));
}

long long solution(string expression) {
    long long answer = 0;
    
    V.clear();
    V.push_back('+');
    V.push_back('-');
    V.push_back('*');
    sort(V.begin(),V.end());
    
    do{
        answer=max(answer,func(expression));
    }while(next_permutation(V.begin(),V.end()));
    
    return answer;
}