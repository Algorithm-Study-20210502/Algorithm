#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

bool check(char c){
    if( (c>='a'&&c<='z') || (c>='A'&&c<='Z')) 
        return true;
    return false;
}

int solution(string str1, string str2) {
    int answer = 0;
    map<string,int>m;
    string temp1="",temp2="";
    for(int i=0;i<str1.length();i++){
        if(str1.at(i)>='a'&&str1.at(i)<='z')
            temp1.push_back(str1.at(i)+'A'-'a');
        else
            temp1.push_back(str1.at(i));
    }
    for(int i=0;i<str2.length();i++){
        if(str2.at(i)>='a'&&str2.at(i)<='z')
            temp2.push_back(str2.at(i)+'A'-'a');
        else
            temp2.push_back(str2.at(i));
    }
    str1=temp1;
    str2=temp2;
    
    vector<string> v1,v2;
    
    double cnt1=0,cnt2=0,cnt=0;
    
    for(int i=0; i < str1.length()-1;i++){
        if(check(str1.at(i))&&check(str1.at(i+1))){
            if(m.find(str1.substr(i,2))!=m.end()){
                m[str1.substr(i,2)]++;
            }else{
                m.insert({str1.substr(i,2),1});
            }
            cnt1++;
        }
            // v1.push_back(str1.substr(i,2));
    }
    
    for(int i=0;i<str2.length()-1;i++){
        if(check(str2.at(i))&&check(str2.at(i+1)))
        {
            cnt2++;
            if(m.find(str2.substr(i,2))!=m.end()){
                int a = m[str2.substr(i,2)];
                if(a>0){
                    m[str2.substr(i,2)] = a-1;
                    cnt++;
                }
                
            }
        }
            // v2.push_back(str2.substr(i,2));
    }
    cout << cnt1 << " " << cnt2 << " " << cnt << endl;
    if(cnt1+cnt2!=cnt)
    {
        double X=cnt/(cnt1+cnt2-cnt);
        printf("%.3f",X);
        answer=X*65536;
    }else{
        answer=65536;
    }
        
    
    
    
    
    return answer;
}