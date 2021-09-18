#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    memset(dp,0,sizeof(dp));
    dp[1][1]=triangle[0][0];
    
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j+1]+triangle[i][j]);
            if(j>=1)
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+triangle[i][j]);
            
            answer=max(answer,dp[i+1][j+1]);
        }
    }
    // cout << dp[2][1] << " " << dp[2][2] << endl;       
    return answer;
}