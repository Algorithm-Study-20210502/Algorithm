#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visit[10001]={false,};

bool dfs(string s,vector<vector<string>> t ,int cnt){
    
    if(cnt==t.size()) return true;
    
    for(int i=0;i<t.size();i++){
        if(s==t[i][0]&&visit[i]==false){
            visit[i]=true;
            answer.push_back(t[i][1]);
            if(dfs(t[i][1],t,cnt+1)){
                return true;
            }else{
                answer.pop_back();
                visit[i]=false;
            }
        }
    }
    return false;
    
}

bool cmp(vector<string>a, vector<string> b){
    return a[1]<b[1];
}

vector<string> solution(vector<vector<string>> tickets) {
    
    sort(tickets.begin(),tickets.end(),cmp);
    answer.push_back("ICN");
    dfs("ICN",tickets,0);
    
    return answer;
}