#include <string>
#include <vector>
#include <cstring>

#define mod 1000000007

using namespace std;

vector<vector<int>> temp;
int M,N;
int arr[101][101];
int dp[101][101];

int calc(int x,int y){
    
    if(dp[x][y]!=-1) return dp[x][y];
    
    if(x==1&&y==1) return dp[x][y]=1;
    if(arr[x][y]==2) return dp[x][y]=0;
    
    if(x==1) return dp[x][y]=calc(x,y-1)%mod;
    if(y==1) return dp[x][y]=calc(x-1,y)%mod;
    
    return dp[x][y]=calc(x-1,y)%mod + calc(x,y-1)%mod;

}

int solution(int m, int n, vector<vector<int>> puddles) {
    
    memset(arr,0,sizeof(arr));
    memset(dp,-1,sizeof(dp));
    for(auto w:puddles){
        int a = w[0];
        int b = w[1];
        arr[a][b]=2;
    }
    
    M=m;
    N=n;
    
    int answer = 0;
    
    answer = calc(m,n)%mod;
    
    return answer;
}