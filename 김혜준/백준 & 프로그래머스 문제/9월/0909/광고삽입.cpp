#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int ad[360000];

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first) return a.first<b.first;
    return a.second < b.second;
}

int strToInt(string s){
        
    int H1 = stoi(s.substr(0,2));
    int M1 = stoi(s.substr(3,2));
    int S1 = stoi(s.substr(6,2));

    return H1*3600+M1*60+S1;
    
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    memset(ad,0,sizeof(ad));
    
    for(auto w:logs){
        string start = w.substr(0,8);
        string end = w.substr(9,8);
        
        int s = strToInt(start);
        int e = strToInt(end);
        
        for(int i=s;i<e;i++){
            ad[i]++;
        }
    }
    
    int playTime = strToInt(play_time);
    int adTime = strToInt(adv_time);
    long long total=0;
    long long ret=0;
    int S=0;
    for(int i=0;i<playTime;i++){
        if(i<adTime){
            total+=ad[i];
            ret=total;
        }else{
            total+=ad[i];
            total-=ad[i-adTime];
            if(ret<total){
                ret=total;
                S=i-adTime+1;
            }
        }
    }
    string s1,s2,s3;
    s1=to_string(S%60);
    S/=60;
    s2=to_string(S%60);
    S/=60;
    s3=to_string(S);
    if(s1.length()==1) s1="0"+s1;
    if(s2.length()==1) s2="0"+s2;
    if(s3.length()==1) s3="0"+s3;
    answer=s3+":"+s2+":"+s1;
    
    return answer;
}