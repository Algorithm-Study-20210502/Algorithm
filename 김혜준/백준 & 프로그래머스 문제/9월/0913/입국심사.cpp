#include <string>
#include <vector>

using namespace std;

vector<int>T;
int N;

bool able(long long n){
    long long total=0;
    for(auto w:T){
        total+=n/w;
    }
    if(total>=N){
        return true;
    }
    return false;
    
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    N=n;
    T=times;
    
    long long l=0;
    long long r=99999999999999;
    
    while(l<=r){
        long long mid = (l+r)/2;
        
        if(able(mid)){
            r=mid-1;
            answer=mid;
        }else{
            l=mid+1;
        }
    }
    
    return answer;
}