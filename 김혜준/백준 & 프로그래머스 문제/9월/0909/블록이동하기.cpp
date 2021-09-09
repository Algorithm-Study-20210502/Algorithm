#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int arr[100][100];
bool visit[100][100][2];
int N;
int dx[2]={0,1};
int dy[2]={1,0};

bool check(int x,int y){
    if(x>=0&&x<N&&y>=0&&y<N)
        return true;
    return false;
}

int solution(vector<vector<int>> board) {
    int ret;
    N=board.size();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            arr[i][j]=board[i][j];
        }
    }
    memset(visit,false,sizeof(visit));
    visit[0][0][0]=true; //0은 가로 1은 세로
    
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,0},{0,0}});
    while(!q.empty()){
        int dir=q.front().first.first;
        int cnt=q.front().first.second;
        int sx=q.front().second.first;
        int sy=q.front().second.second;
        q.pop();
        
        int ex,ey;
        if(dir==0){
            ex=sx;
            ey=sy+1;
        }else{
            ex=sx-1;
            ey=sy;
        }
        
        cout << sx << " " << sy << " " << ex << " " << ey << "   " << dir<<" "<<cnt<< endl;
        
        if(sx==N-1&&sy==N-1){
            ret=cnt;
            break;
        }
        
        if(ex==N-1&&ey==N-1){
            ret=cnt;
            break;
        }
        int enx,eny;
        //회전하지 않는경우
        
        int nx,ny,snx,sny;
        //앞으로 가는 경우
        
        if(dir==0){
            //오른쪽
            snx=ex;
            sny=ey;
            enx=snx;
            eny=sny+1;
            
            if(check(snx,sny)&&check(enx,eny)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0){
                    if(visit[snx][sny][0]==false){
                        visit[snx][sny][0]=true;
                        q.push({{0,cnt+1},{snx,sny}});
                    }
                }
            }
            
            //왼쪽
            snx=sx;
            sny=sy-1;
            enx=snx;
            eny=sny+1;
            
            if(check(snx,sny)&&check(enx,eny)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0){
                    if(visit[snx][sny][0]==false){
                        visit[snx][sny][0]=true;
                        q.push({{0,cnt+1},{snx,sny}});
                    }
                }
            }
        }else{
            //위로
            snx=ex;
            sny=ey;
            enx=snx-1;
            eny=sny;
            
            if(check(snx,sny)&&check(enx,eny)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0){
                    if(visit[snx][sny][1]==false){
                        visit[snx][sny][1]=true;
                        q.push({{1,cnt+1},{snx,sny}});
                    }
                }
            }
            //아래로
            snx=sx+1;
            sny=sy;
            enx=snx-1;
            eny=sny;
            
            if(check(snx,sny)&&check(enx,eny)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0){
                    if(visit[snx][sny][1]==false){
                        visit[snx][sny][1]=true;
                        q.push({{1,cnt+1},{snx,sny}});
                    }
                }
            }
            
        }
        
        //옆으로 가는 경우
        if(dir==0){
            snx=sx+1;
            sny=sy;
            enx=snx;
            eny=sny+1;
            
            if(check(snx,sny)&&check(enx,eny)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0){
                    if(visit[snx][sny][0]==false){
                        visit[snx][sny][0]=true;
                        q.push({{0,cnt+1},{snx,sny}});
                    }
                }
            }
            
            snx=sx-1;
            sny=sy;
            enx=snx;
            eny=sny+1;
            
            if(check(snx,sny)&&check(enx,eny)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0){
                    if(visit[snx][sny][0]==false){
                        visit[snx][sny][0]=true;
                        q.push({{0,cnt+1},{snx,sny}});
                    }
                }
            }
            
        }else{
            
            snx=sx;
            sny=sy+1;
            enx=snx-1;
            eny=sny;
            
            if(check(snx,sny)&&check(enx,eny)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0){
                    if(visit[snx][sny][1]==false){
                        visit[snx][sny][1]=true;
                        q.push({{1,cnt+1},{snx,sny}});
                    }
                }
            }
            
            snx=sx;
            sny=sy-1;
            enx=snx-1;
            eny=sny;
            
            if(check(snx,sny)&&check(enx,eny)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0){
                    if(visit[snx][sny][1]==false){
                        visit[snx][sny][1]=true;
                        q.push({{1,cnt+1},{snx,sny}});
                    }
                }
            }
            
            
        }
        
        //회전 하는 경우
        int ckx,cky;
        if(dir==0){
            //왼쪽 축 중심
            //시계방향
            snx=ex+1;
            sny=ey-1;
            enx=snx-1;
            eny=sny;
            ckx=sx+1;
            cky=sy+1;
            
            if(check(snx,sny)&&check(enx,eny)&&check(ckx,cky)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0&&arr[ckx][cky]==0){
                    if(visit[snx][sny][1]==false){
                        visit[snx][sny][1]=true;
                        q.push({{1,cnt+1},{snx,sny}});
                    }
                }
            }
            
            //반시계방향
            snx=sx;
            sny=sy;
            enx=snx-1;
            eny=sny;
            ckx=sx-1;
            cky=sy+1;
            
            if(check(snx,sny)&&check(enx,eny)&&check(ckx,cky)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0&&arr[ckx][cky]==0){
                    if(visit[snx][sny][1]==false){
                        visit[snx][sny][1]=true;
                        q.push({{1,cnt+1},{snx,sny}});
                    }
                }
            }
            
            //오른쪽 축 중심
            //시계방향
            snx=ex;
            sny=ey;
            enx=snx-1;
            eny=sny;
            ckx=sx-1;
            cky=sy;
            
            if(check(snx,sny)&&check(enx,eny)&&check(ckx,cky)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0&&arr[ckx][cky]==0){
                    if(visit[snx][sny][1]==false){
                        visit[snx][sny][1]=true;
                        q.push({{1,cnt+1},{snx,sny}});
                    }
                }
            }
            
            //반시계방향
            snx=sx+1;
            sny=sy+1;
            enx=snx-1;
            eny=sny;
            ckx=sx+1;
            cky=sy;
            
            if(check(snx,sny)&&check(enx,eny)&&check(ckx,cky)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0&&arr[ckx][cky]==0){
                    if(visit[snx][sny][1]==false){
                        visit[snx][sny][1]=true;
                        q.push({{1,cnt+1},{snx,sny}});
                    }
                }
            }
            
        }else{// 세로방향 시작
            
            //아래축 중심
            // 시계방향
            snx=sx;
            sny=sy;
            enx=snx;
            eny=sny+1;
            ckx=sx-1;
            cky=sy+1;
            
            if(check(snx,sny)&&check(enx,eny)&&check(ckx,cky)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0&&arr[ckx][cky]==0){
                    if(visit[snx][sny][0]==false){
                        visit[snx][sny][0]=true;
                        q.push({{0,cnt+1},{snx,sny}});
                    }
                }
            }
            
            //반시계방향
            snx=sx;
            sny=sy-1;
            enx=snx;
            eny=sny+1;
            ckx=sx-1;
            cky=sy-1;
            
            if(check(snx,sny)&&check(enx,eny)&&check(ckx,cky)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0&&arr[ckx][cky]==0){
                    if(visit[snx][sny][0]==false){
                        visit[snx][sny][0]=true;
                        q.push({{0,cnt+1},{snx,sny}});
                    }
                }
            }
            
            //위축 중심
            //시계방향
            snx=ex;
            sny=ey-1;
            enx=snx;
            eny=sny+1;
            ckx=ex+1;
            cky=ey-1;
            
            if(check(snx,sny)&&check(enx,eny)&&check(ckx,cky)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0&&arr[ckx][cky]==0){
                    if(visit[snx][sny][0]==false){
                        visit[snx][sny][0]=true;
                        q.push({{0,cnt+1},{snx,sny}});
                    }
                }
            }
            //반시계방향
            snx=ex;
            sny=ey;
            enx=snx;
            eny=sny+1;
            ckx=ex+1;
            cky=ey+1;
            
            if(check(snx,sny)&&check(enx,eny)&&check(ckx,cky)){
                if(arr[snx][sny]==0&&arr[enx][eny]==0&&arr[ckx][cky]==0){
                    if(visit[snx][sny][0]==false){
                        visit[snx][sny][0]=true;
                        q.push({{0,cnt+1},{snx,sny}});
                    }
                }
            }
            
            
        }
    }
    return ret;
}