#include <string>
#include <vector>
#include <iostream>

#define INF 99999999

using namespace std;

int dist[201][201];

void init(){

    
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    
    for(int i=0;i<fares.size();i++){
        int a = fares[i][0];
        int b = fares[i][1];
        int cost = fares[i][2];
        dist[a][b]=cost;
        dist[b][a]=cost;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF){
                    dist[i][j] = min(dist[i][k]+dist[k][j],dist[i][j]);
                }
            }
        }
    }
    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    int answer = 0;
    
    answer=dist[s][a]+dist[s][b];
    
    for(int i=1;i<=n;i++){
        // if(a==i||b==i) continue;
        answer=min(answer,dist[s][i]+dist[i][a]+dist[i][b]);
    }
    
    return answer;
}

// s->a
// s->b

// s->a
// s->b

// s ->n ->a
// s ->n ->b