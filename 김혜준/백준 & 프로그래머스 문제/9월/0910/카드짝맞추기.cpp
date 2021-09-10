#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
int arr[4][4];
vector<pair<int,int>> P[7];
bool visit[7];

int func(int x,int y,int ex,int ey){
    int dx=ex-x;
    int dy=ey-y;
    
    if(dx==0&&dy==0){
        return 0;
    }else if(dx==0){
        vector<pair<int,int>> temp;
        int DY=99;
        int yy=dy/abs(dy);
        int cnt=0;
        temp.push_back({0,y});
        for(int i=y+yy;i!=4&&i!=-1;i+=yy){
        if(arr[ex][i]!=0&&visit[arr[ex][i]]==false || i==3 || i==0){
            cnt++;
            temp.push_back({cnt,i});
        }
        }

        for(auto w:temp){
            DY = min(DY,abs(w.second-ey)+w.first);
        }
        // cout <<"!"<< x <<" "<< y <<" "<< ex <<" "<< ey <<" "<< DY << endl;
        return DY;
    }else if(dy==0){
        vector<pair<int,int>> temp;
        int DX=99;
        int xx=dx/abs(dx);
        int cnt=0;
        temp.push_back({0,x});
        for(int i=x+xx;i!=4&&i!=-1;i+=xx){
        if(arr[i][ey]!=0&&visit[arr[i][ey]]==false || i==3 || i==0){
            cnt++;
            temp.push_back({cnt,i});
        }
        }

        for(auto w:temp){
            DX = min(DX,abs(w.second-ex)+w.first);
        }
        // cout <<"@"<< x <<" "<< y <<" "<< ex <<" "<< ey <<" "<< DX << endl;
        return DX;
    }
    
    int X=abs(dx);
    int Y=abs(dy);
    
    int xx=dx/X;
    int yy=dy/Y;
    
    vector<pair<int,int>> temp;
    int DX=99,DY=99;
    int cnt=0;
    temp.push_back({0,x});
    // x->y
    for(int i=x+xx;i!=4&&i!=-1;i+=xx){
        if(arr[i][y]!=0&&visit[arr[i][y]]==false || i==3||i==0){
            cnt++;
            temp.push_back({cnt,i});
        }
    }
    
    for(auto w:temp){
        DX = min(DX,abs(w.second-ex)+w.first);
    }
    
    cnt=0;
    temp.clear();
    temp.push_back({0,y});
    // ex,y->ex,ey
    
    for(int i=y+yy;i!=4&&i!=-1;i+=yy){
        if(arr[ex][i]!=0&&visit[arr[ex][i]]==false || i==3 || i==0){
            cnt++;
            temp.push_back({cnt,i});
        }
    }
    
    for(auto w:temp){
        DY = min(DY,abs(w.second-ey)+w.first);
    }
    
    int ret = DX+DY;
    
    DX=99,DY=99;
    cnt=0;
    temp.clear();
    temp.push_back({0,y});
    // y->x
    for(int i=y+yy;i!=4&&i!=-1;i+=yy){
        if(arr[x][i]!=0&&visit[arr[x][i]]==false || i==3||i==0){
            cnt++;
            temp.push_back({cnt,i});
        }
    }
    
    for(auto w:temp){
        DY = min(DY,abs(w.second-ey)+w.first);
    }
    
    cnt=0;
    temp.clear();
    temp.push_back({0,x});
    // x,ey->ex,ey
    
    for(int i=x+xx;i!=4&&i!=-1;i+=xx){
        if(arr[i][ey]!=0&&visit[arr[i][ey]]==false || i==3 || i==0){
            cnt++;
            temp.push_back({cnt,i});
        }
    }
    
    for(auto w:temp){
        DX = min(DX,abs(w.second-ex)+w.first);
    }
    
    ret=min(ret,DX+DY);
    
    // cout << x <<" "<< y <<" "<< ex <<" "<< ey <<" "<< ret << endl;
    return ret;
    
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 99999;
    int cnt=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            arr[i][j]=board[i][j];
            if(board[i][j]!=0){
                cnt++;
                P[board[i][j]].push_back({i,j});
            }
        }
    }
    cnt/=2;
    vector<int>V;
    
    
    
    for(int i=1;i<=cnt;i++){
        V.push_back(i);
        visit[i]=false;
    }
    
    int cx=r,cy=c;
    
    do{
        memset(visit,false,sizeof(visit));
        vector<pair<pair<int,int>,int>>pos;
        pos.push_back({{cx,cy},0});
        
        for(int i=0;i<cnt;i++){
            int go = V[i];
            
            int nx1 = P[go][0].first;
            int ny1 = P[go][0].second;
            
            int nx2 = P[go][1].first;
            int ny2 = P[go][1].second;
            
            vector<pair<pair<int,int>,int>>Tpos;
            for(int j=0;j<pos.size();j++){
                int curX = pos[j].first.first;
                int curY = pos[j].first.second;
                int curD = pos[j].second;
                int d1 = func(curX,curY,nx1,ny1)+func(nx1,ny1,nx2,ny2);
                int d2 = func(curX,curY,nx2,ny2)+func(nx2,ny2,nx1,ny1);
                // cout << nx2 << " "<< ny2 << " "<< curD+d1 << endl;
                // cout << nx1 << " "<< ny1 << " "<< curD+d2 << endl;
                Tpos.push_back({{nx2,ny2},curD+d1});
                Tpos.push_back({{nx1,ny1},curD+d2});
            }
            pos=Tpos;
            visit[V[i]]=true;
        }
        for(auto w:pos){
            answer = min(answer,w.second);
        }
        
        
    }while(next_permutation(V.begin(),V.end()));
    
    // 1. 그냥 이동
    // 2. 한번에 이동
    answer+=cnt*2;
    return answer;
}