#include <string>
#include <vector>
#define MOD 1234567

using namespace std;

int dp[2001]={0,};

long long solution(int n) {
    long long answer = 0;
    
    dp[0]=1;
    for(int i=0;i<=n-2;i++){
        if(dp[i]){
            dp[i+1]+=dp[i];
            dp[i+1]%=MOD;
            dp[i+2]+=dp[i];
            dp[i+2]%=MOD;
        }
    }
    dp[n]+=dp[n-1];
    dp[n]%=MOD;
    return dp[n];
    // return answer;
}