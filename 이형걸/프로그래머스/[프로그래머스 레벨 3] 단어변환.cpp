// dfs, bfs 모두 가능한 문제

#include <string>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

int Answer = INF;
vector<bool> Visited;

void dfs(string begin, string target, vector<string>& words, int count);

int solution(string begin, string target, vector<string> words) {
    Visited.resize(words.size(), false);
    
    dfs(begin, target, words, 0);
    
    if(Answer == INF) {
        Answer = 0;
    }
    
    return Answer;
}

void dfs(string begin, string target, vector<string>& words, int count) {
    if(begin == target) {
        Answer = min(Answer, count);
        return;
    }
    
    for(int i = 0; i < words.size(); ++i) {
        int cnt = 0;
        for(int j = 0; j < words[i].length(); ++j) {
            if(begin[j] != words[i][j]) {
                ++cnt;
            }
        }
        
        if(cnt == 1 && !Visited[i]) {
            Visited[i] = true;
            dfs(words[i], target, words, count + 1);
            Visited[i] = false;
        }
    }
}