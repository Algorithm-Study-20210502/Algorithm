#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

bool check(string s1, string s2){
    int total=0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
            total++;
        }
        if(total>=2) return false;
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool visit[51];
    vector<int>adj[51];
    for(int i=0;i<words.size();i++){
        if(check(begin,words[i])){
            adj[0].push_back(i+1);
        }
    }
    
    for(int i=0;i<words.size();i++){
        for(int j=i+1;j<words.size();j++){
            if(check(words[i],words[j])){
                adj[i+1].push_back(j+1);
                adj[j+1].push_back(i+1);
            }
        }
    }
    
    memset(visit,false,sizeof(visit));
    
    queue<pair<int,int>> q;
    q.push({0,0});
    
    while(!q.empty()){
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        for(auto w:adj[cur]){
            if(visit[w]) continue;
            if(target == words[w-1]) return dist+1;
            q.push({w,dist+1});
            visit[w]=true;
        }
    }
    
    return answer;
}