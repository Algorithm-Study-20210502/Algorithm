#include <string>
#include <vector>
#include <iostream>

#define MAX 2000000000000000

using namespace std;

int A,B;
vector<int> G,S,W,T;

bool able(long long m){
    // cout << m << endl;
    long long gtotal = 0, stotal =0, wtotal=0;
    
    for(int i=0;i<G.size();i++){
        long long cnt = 1 + (m - T[i])/(2*T[i]);
        if(m<T[i]) cnt=0;
        
        if(cnt*W[i]<G[i]){
            gtotal += cnt*W[i];
        }else{
            gtotal += G[i];
        }
        
        if(cnt*W[i]<S[i]){
            stotal += cnt*W[i];
        }else{
            stotal += S[i];
        }
        
        if(cnt*W[i] < G[i]+S[i]){
            wtotal += cnt * W[i];
        }else{
            wtotal += G[i] + S[i];
        }
    }
    // cout << stotal << " " << gtotal << " " << wtotal << endl;
    
    if(A<=gtotal && B<=stotal && A+B <= wtotal){
        return true;
    }
    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    A=a;
    B=b;
    G=g;
    S=s;
    W=w;
    T=t;
    long long l=0;
    long long r=MAX;
    
    while(l<=r){
        long long mid = (l+r)/2;
        
        if(able(mid)){
            r = mid - 1;
            answer = mid;
        }else{
            l = mid + 1;
        }
    }
    
    return answer;
}