#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> Select;
vector<string> Results;

void dfs(string temp, int startIndex, int cnt, int n);

vector<int> solution(int n, long long k) {
    vector<int> answer;
    Select.resize(n+1, false);
    
    dfs("",1,0,n);
    
    string result = Results[k-1];
    
    for(char r : result) {
        answer.push_back(r-'0');
    }
    
    return answer;
}

void dfs(string temp, int startIndex, int cnt, int n) {
    if(cnt == n) {
        Results.push_back(temp);
        return;
    }
    
    for(int i = startIndex; i <= n; ++i) {
        if(Select[i]) {
            continue;
        }
        temp += to_string(i);
        Select[i] = true;
        dfs(temp, i, cnt+1, n);
        Select[i] = false;
        temp.pop_back();
    }
}