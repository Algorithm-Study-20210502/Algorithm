#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for(auto w:s){
        string temp = "";
        int cnt=0;
        for(int i=0;i<w.length();i++){
            temp+=w[i];
            if(temp.length()>=3){
                if(temp.substr(temp.length()-3)=="110"){
                    cnt++;
                    temp = temp.substr(0,temp.length()-3);
                }
            }
        }
        bool flag=false;
        string temp2="";
        for(int j=0;j<cnt;j++){
            temp2+="110";
        }
        for(int i=temp.length()-1;i>=0;i--){
            if(temp[i]=='0'){
                
                string s1 = temp.substr(0,i+1);
                string s2 = temp.substr(i+1);
                string ret = s1+temp2+s2;
                answer.push_back(ret);
                flag=true;
                break;
            }
        }
        if(flag==false){
            temp2+=temp;
            answer.push_back(temp2);
        }
        
    }
    
    return answer;
}