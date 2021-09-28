#include <string>
#include <vector>

using namespace std;

vector<int>adj[300001];
vector<long long> A;
long long answer = 0;

void dfs(int root, int cur){
    
    for(auto w:adj[cur]){
        if(w==root) continue;
        dfs(cur,w);
    }
    answer += abs(A[cur]);
    A[root]+=A[cur];
    A[cur]=0;
    
    
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    
    
    long long total=0;
    for(auto w:a){
        A.push_back(w);
        total+=w;
    }
    if(total!=0) return -1;
    
    for(auto w:edges){
        int a = w[0];
        int b = w[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0,0);
    
    return answer;
}