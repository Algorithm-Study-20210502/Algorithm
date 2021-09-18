#include <string>
#include <vector>
#include <cstring>

#define mod 1000000007

using namespace std;

int dp[60001];

int solution(int n) {
    int answer = 0;
    
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i] += dp[i-1];
        dp[i]%=mod;
        dp[i] += dp[i-2];
        dp[i]%=mod;
    }
    answer = dp[n];
    return answer;
}