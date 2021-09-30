#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int dp[100001]={0,};

int solution(int n, vector<int> money) {
    int answer = 0;
    dp[0]=1;
    for(auto w:money){
        for(int i=0;i<=n-w;i++){
            if(dp[i]){
                dp[i+w]+=dp[i];
                dp[i+w]%=MOD;
            }
        }
    }
    answer = dp[n];
    return answer;
}