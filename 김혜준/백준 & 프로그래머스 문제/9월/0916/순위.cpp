#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> adj1[101],adj2[101];
bool visit[101];
int cnt;

void dfs1(int n){
    cnt++;
    visit[n]=true;
    
    for(auto w:adj1[n]){
        if(visit[w]==false) dfs1(w);
    }   
}

void dfs2(int n){
    cnt++;
    visit[n]=true;
    
    for(auto w:adj2[n]){
        if(visit[w]==false) dfs2(w);
    }   
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for(auto w:results){
        int A = w[0];
        int B = w[1];
        
        adj1[A].push_back(B);
        adj2[B].push_back(A);
    }
    
    for(int i=1;i<=n;i++){
        cnt=0;
        memset(visit,false,sizeof(visit));
        dfs1(i);
        dfs2(i);
        if(cnt==n+1) answer++;
    }

    return answer;
}