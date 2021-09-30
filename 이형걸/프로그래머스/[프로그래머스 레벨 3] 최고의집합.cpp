#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int mid = s/n;
    int remain = s%n;
    
    if(mid == 0) {
        answer.push_back(-1);
        return answer;
    }
    
    for(int i = 0; i < n; ++i) {
        if(i >= n-remain) {
            answer.push_back(mid+1);
        }
        else {
            answer.push_back(mid); 
        }
    }
   
    return answer;
}