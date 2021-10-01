#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(auto w:works){
        pq.push(w);
    }
    
    while(n!=0){
        if(pq.empty()) break;
        int cur = pq.top();
        pq.pop();
        n--;
        if(cur-1==0) continue;
        pq.push(cur-1);
    }
    while(!pq.empty()){
        answer+=pq.top()*pq.top();
        pq.pop();
    }
    
    
    return answer;
}