#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int MOD;
int dp[500][500][2];
int arr[500][500];

int calc(int x,int y,int dir){
    
    if(dp[x][y][dir]!=-1){
        return dp[x][y][dir];
    }
    if(x==0||y==0) return dp[x][y][dir]=0;
    
    dp[x][y][dir]=0;
    if(dir==0){
        if(arr[x-1][y]==1){
            return dp[x][y][dir] = 0;
        }else if(arr[x-1][y]==0){
            return dp[x][y][dir] = (calc(x-1,y,0)% 20170805 + calc(x-1,y,1)% 20170805)% 20170805;
        }else{
            return dp[x][y][dir] = calc(x-1,y,0) % 20170805;
        }
    }else{
        if(arr[x][y-1]==1){
            return dp[x][y][dir] = 0;
        }else if(arr[x][y-1]==0){
            return dp[x][y][dir] = (calc(x,y-1,0)% 20170805 + calc(x,y-1,1) % 20170805)% 20170805;
        }else{
            return dp[x][y][dir] = calc(x,y-1,1) % 20170805;
        }
    }
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    MOD=20170805;
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=1;
    dp[0][0][1]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = city_map[i][j];
        }
    }
    
    for(int i=1;i<n;i++){
        if(arr[0][i]==1)
            break;
        dp[0][i][1]=1;
        dp[0][i][0]=0;
    }
    for(int i=1;i<m;i++){
        if(arr[i][0]==1)
            break;
        dp[i][0][0]=1;
        dp[i][0][1]=0;
    }
    
    answer = calc(m-1,n-1,0) % 20170805 + calc(m-1,n-1,1)% 20170805;
    
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout << dp[i][j][0] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // cout << endl;
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout << dp[i][j][1] << ' ';
    //     }
    //     cout << endl;
    // }
    
    
    return answer% 20170805;
}