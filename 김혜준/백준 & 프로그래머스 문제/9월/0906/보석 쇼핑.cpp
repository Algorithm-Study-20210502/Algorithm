#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string,int> mm;
    int L,R;
    int start=0;
    int end=0;
    for(int i=0;i<gems.size();i++){
        string cur = gems[i];
        if(mm[cur]==0){
            end=max(end,i);
            mm[cur]++;
        }
    }
    int ret=end-start;
    L=start;
    R=end;
    map<string,int>m;
    for(int i=start;i<=end;i++){
        m[gems[i]]++;
    }
    
    while(end<gems.size()){
        while(m[gems[start]]>1){
            m[gems[start++]]--;
        }
        if(ret>end-start){
            ret=end-start;
            L = start;
            R = end;
        }
        end++;
        if(end==gems.size())
            break;
        m[gems[end]]++;
    }
    // cout << ret;
    answer.push_back(L+1);
    answer.push_back(R+1);
    return answer;
}