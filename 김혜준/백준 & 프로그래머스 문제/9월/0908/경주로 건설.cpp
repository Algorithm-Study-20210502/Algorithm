#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int visit[25][25][2];

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int X = board.size();
    int Y = board[0].size();
    int N=X;
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,0},{0,0}});
    q.push({{0,0},{1,0}});
    memset(visit,-1,sizeof(visit));
    visit[0][0][0]=0;
    visit[0][0][1]=0;
    
    int ret=999999999;
    
    while(!q.empty()){
        
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        
        int cdir = q.front().second.first;
        int cost = q.front().second.second;
        // cout << cx << " " << cy << " " << cdir << " "<< cost << endl;
        q.pop();
        
        for(int i=0;i<4;i++){ // 0,1은 세로, 2,3은 가로
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N ){
                if(board[nx][ny]==0){
                    if(i<2){ // 세로방향
                        if(cdir==0) // 세로방향이었는데 세로방향으로
                        {
                            if(visit[nx][ny][0]==-1||visit[nx][ny][0]>cost+100){
                                if(nx==N-1&&ny==N-1){
                                    ret=min(ret,cost+100);
                                    continue;
                                }
                                q.push({{nx,ny},{0,cost+100}});
                                visit[nx][ny][0]=cost+100;
                            }
                        }else{ // 가로방향이었는데 세로방향으로
                            if(visit[nx][ny][0]==-1||visit[nx][ny][0]>cost+600){
                                if(nx==N-1&&ny==N-1){
                                    ret=min(ret,cost+600);
                                    continue;
                                }
                                q.push({{nx,ny},{0,cost+600}});
                                visit[nx][ny][0]=cost+600;
                            }
                        }
                    }else{ // 가로방향
                        if(cdir==1) // 가로방향
                        {
                            // if(nx==2&&ny==2)
                            //     cout << "##" << visit [nx][ny][1] << endl;
                            if(visit[nx][ny][1]==-1||visit[nx][ny][1]>cost+100){
                                if(nx==N-1&&ny==N-1){
                                    ret=min(ret,cost+100);
                                    continue;
                                }
                                q.push({{nx,ny},{1,cost+100}});
                                visit[nx][ny][1]=cost+100;
                            }
                        }else{
                            if(visit[nx][ny][1]==-1||visit[nx][ny][1]>cost+600){
                                if(nx==N-1&&ny==N-1){
                                    ret=min(ret,cost+600);
                                    continue;
                                }
                                q.push({{nx,ny},{1,cost+600}});
                                visit[nx][ny][1]=cost+600;
                            }
                        }
                    }
                }
            }
            
        }
        
    }
    answer=ret;
    
    return answer;
}