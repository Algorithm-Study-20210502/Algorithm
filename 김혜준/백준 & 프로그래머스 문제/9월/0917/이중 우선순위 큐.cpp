#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <set>

using namespace std;

priority_queue<int> pq1,pq2;
map<int,int> m;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    for(auto w:operations){
        if(w[0]=='I'){
            // pq1.push(stoi(w.substr(2)));
            // pq2.push(-stoi(w.substr(2)));
            ms.insert(stoi(w.substr(2)));
        }else{
            int t = stoi(w.substr(2));
            if(t==-1){
                // pq1.pop();
                if(ms.empty())continue;
                auto it = ms.begin();
                // cout << *it << endl;
                ms.erase(it);
            }else{
                // pq2.pop();
                if(ms.empty())continue;
                auto it = ms.end();
                it--;
                // cout << *it << endl;
                ms.erase(it);
            }
        }
    }
    if(ms.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        
        auto it=ms.end();
        it--;
        answer.push_back(*it);
        it = ms.begin();
        answer.push_back(*it);
    }
    
    
    return answer;
}