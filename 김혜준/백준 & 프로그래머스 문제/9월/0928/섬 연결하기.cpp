#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef struct info{
    int a,b,cost;
}info;

struct cmp{
    bool operator()(info a,info b){
        return a.cost > b.cost;     
    }
};

priority_queue<info,vector<info>,cmp> pq;
int Rank[101];
int parent[101];

int find(int n){
    while(parent[n]!=n){
        n=parent[n];
    }
    return n;
}

void Union(int a, int b){
    
    if(Rank[a]>Rank[b]){
        parent[b]=a;
    }else if(Rank[b]>Rank[a]){
        parent[a]=b;
    }else{
        parent[a]=b;
        Rank[b]++;
    }
    
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i=1;i<=n;i++){
        parent[i]=i;
        Rank[i]=1;
    }
    
    for(auto w:costs){
        int a = w[0];
        int b = w[1];
        int cost = w[2];
        
        info c;
        c.a=a;
        c.b=b;
        c.cost=cost;
        pq.push(c);
    }
    
    while(!pq.empty()){
        info cur = pq.top();
        int a = cur.a;
        int b = cur.b;
        int cost = cur.cost;
        
        int fa = find(a);
        int fb = find(b);
        
        // cout << cost << endl;
        pq.pop();
        
        if(fa!=fb){
            Union(fa,fb);
            answer+=cost;
        }
        
    }
    
    return answer;
}