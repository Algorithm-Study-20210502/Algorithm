#include <vector>
#include <iostream>


using namespace std;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    int INF=999999999;
    
    vector<int>adj[n+1];
    
    for(auto w:edge_list){
        int a = w[0];
        int b = w[1];
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    int dp[k][n+1]; // 0번째~ k-1번째 /// n+1인 경우
    
    for(int i=0;i<k;i++){
        for(int j=0;j<n+1;j++){
            dp[i][j]=INF;
        }
    }
    int start = gps_log[0];
    int end = gps_log[k-1];
    
    dp[0][start]=0;
    
    
    for(int i=1;i<k;i++){
        for(int j=1;j<=n;j++){ // 1부터 n까지
            
            // dp[i][j]를 갱신할건데
            
            int minValue = dp[i-1][j]; //그대로인 경우
            
            for(int l=0;l<adj[j].size();l++){
                int next = adj[j][l];
                minValue = min(minValue,dp[i-1][next]); //그 전 연결되어있는곳에서 오는 경우
            }
            
            if(gps_log[i]!=j){ 
                dp[i][j] = minValue+1;
            }else{
                dp[i][j] = minValue;
            }
        }
    }
    answer = dp[k-1][end];
    if(answer>=INF) answer=-1;
    return answer;
}