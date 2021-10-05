#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int cur=0;
    for(auto w:A){
        while(w>=B[cur]&&cur<B.size()){
            cur++;
        }
        if(cur==B.size())
            break;
        cur++;
        answer++;
        if(cur==B.size())
            break;
    }
    
    return answer;
}