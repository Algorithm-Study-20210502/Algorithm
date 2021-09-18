#include <string>
#include <vector>
#include <set>

using namespace std;

int N;
int parent[201];
int Rank[201];

void init(){
    for(int i=0;i<N;i++){
        parent[i]=i;
        Rank[i]=1;
    }
}

int find(int a){
    while(parent[a]!=a){
        a=parent[a];
    }
    return a;
}

void Union(int a, int b){
    if(Rank[a]>Rank[b]){
        parent[b]=a;
    }else if(Rank[a]<Rank[b]){
        parent[a]=b;
    }else{
        parent[a]=b;
        Rank[b]+=1;
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N=n;
    init();
    
    for(int i=0;i<computers.size();i++){
        for(int j=0;j<computers[i].size();j++){
            if(computers[i][j]==1){
                int af=find(i);
                int bf=find(j);
                if(af!=bf) Union(af,bf);
            }
        }
    }
    
    set <int> S;
    for(int i=0;i<n;i++){
        S.insert(find(i));
    }
    answer=S.size();
    return answer;
}