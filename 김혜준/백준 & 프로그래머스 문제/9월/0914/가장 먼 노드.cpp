#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> adj[20001];
bool visit[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(auto w:edge){
        int a = w[0];
        int b = w[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(visit,false,sizeof(visit));
    queue<pair<int,int>> q;
    q.push({1,0});
    visit[1]=true;
    int DIST=0;
    while(!q.empty()){
        int cur = q.front().first;
        int cur_dist = q.front().second;
        
        if(DIST<cur_dist){
            DIST = cur_dist;
            answer=1;
        }else if(DIST == cur_dist){
            answer++;
        }
        
        q.pop();
        
        for(auto w : adj[cur]){
            if(visit[w]) continue;
            visit[w]=true;
            q.push({w,cur_dist+1});
            
        }
        
    }
    
    
    return answer;
}