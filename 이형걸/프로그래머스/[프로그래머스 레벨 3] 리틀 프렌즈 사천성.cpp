#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
map<char, pii> Map;

pii bfs(int m, int n, vector<string> board, pii start);

string solution(int m, int n, vector<string> board) {
    string answer = "";
    
    for(int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board[i].length(); ++j) {
            if(isalpha(board[i][j])) {
                Map[board[i][j]] = {i,j};
            }
        }
    }
        
    while(true) {
        bool flag = false;
        
        for(auto x : Map) {
            char alphabet = x.first;
            pii start = x.second;
            pii end = bfs(m, n, board, start);
            
            if(end.first != -1 && end.second != -1) {
                flag = true;
                board[start.first][start.second] = '.';
                board[end.first][end.second] = '.';
                answer += alphabet;
                Map.erase(alphabet);
                break;
            }
        }
        
        if(flag) {
            continue;
        }
        
        if(Map.empty()) {
            break;
        }
        else{
            answer = "IMPOSSIBLE";
            break;
        }
    } 
    
    return answer;
}


pii bfs(int m, int n, vector<string> board, pii start) {
    queue<piiii> q;
    vector<vector<int>> turnCount(m, vector<int>(n, 3));
    pii result = {-1, -1};
    
    q.push({{-1,0}, {start.first, start.second}});
    turnCount[start.first][start.second] = 0;
    
    bool isFirst = true;
    
    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int curD = q.front().first.first;
        int curTurn = q.front().first.second;
        q.pop();
        
        if(!isFirst && board[x][y] == board[start.first][start.second]) {
            result = {x,y};
            break;
        }
        
        isFirst = false;
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nextTurn = curTurn;
            
            if(curD != -1 && curD != i) {
                ++nextTurn;
            }
            
            if(0 <= nx && nx < m && 0 <= ny && ny < n) {
                if(board[nx][ny] == '.' || board[nx][ny] == board[start.first][start.second]) {
                    if(nextTurn < 2 && turnCount[nx][ny] >= nextTurn) {
                        turnCount[nx][ny] = nextTurn;
                        q.push({{i, nextTurn}, {nx,ny}});
                    }
                }
            }
        }
    }
    
    return result;
}