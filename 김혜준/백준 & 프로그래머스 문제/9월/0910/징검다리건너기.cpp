#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> S;
int K;

bool able(int n){

    for(int i=0;i<S.size();i++){
        if(S[i]>n){
            continue;
        }else{
            bool flag=true;
            for(int j=0;j<K;j++){
                if(i+j==S.size()){
                    return true;
                }
                if(S[i+j]>n){
                    i=i+j;
                    flag=false;
                    break;
                }
            }
            if(flag) return false;
        }
    }
}

int solution(vector<int> stones, int k) {
    int answer = -1;
    K=k;
    vector<int>temp=stones;
    S = stones;
    sort(temp.begin(),temp.end());
    int l=1;
    int r=200000000;
    
    while(l<=r){
        int mid=(l+r)/2;
        
        if(able(mid)){
            l=mid+1;
            answer=mid;
        }else{
            r=mid-1;
        }
    }
    
    return answer+1;
}