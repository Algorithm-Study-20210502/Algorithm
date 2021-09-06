#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string,int>m;
int cur;

void init(){
    char a='A';
    for(int i=1;i<=26;i++){
        char X = a+i-1;
        string temp="";
        temp.push_back(X);
        m.insert({temp,i});
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    init();
    cur=27;
    int i=1;
    int cnt=0;
    // cout << m["O"] << endl;
    while(msg!=""){
        
        while(m.find(msg.substr(0,i))!=m.end() && msg.substr(0,i)!=msg){
            i++;
        }
        if(m.find(msg)!=m.end()){
            answer.push_back(m[msg]);
            break;
        }
        m.insert({msg.substr(0,i),cur++});
        answer.push_back(m[msg.substr(0,i-1)]);
        msg = msg.substr(i-1);
        i=1;
        if(m.find(msg)!=m.end()){
            answer.push_back(m[msg]);
            break;
        }
    }
    
    
    
    return answer;
}