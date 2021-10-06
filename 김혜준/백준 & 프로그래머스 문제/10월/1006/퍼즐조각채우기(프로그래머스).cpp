#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int block[50][50];
int game[50][50];
int visit[50][50]={0,};
int visit2[50][50]={0,};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int x1,x2,y1,y2;
int N;
int cur;
int count;

bool check(int x,int y){
    if(x>=0&&x<N&&y>=0&&y<N)
        return true;
    return false;
}

void dfs2(int x,int y, int cnt){
    count++;
    visit2[x][y]=cnt;
    x1=min(x,x1);
    y1=min(y,y1);

    x2=max(x,x2);
    y2=max(y,y2);
    
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(check(nx,ny)){
            if(!game[nx][ny]){
                if(visit2[nx][ny]==0){
                    dfs2(nx,ny,cnt);
                }
            }
        }
    }
}

void dfs(int x, int y, int cnt){
    
    visit[x][y]=cnt;
    x1=min(x,x1);
    y1=min(y,y1);

    x2=max(x,x2);
    y2=max(y,y2);
    
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(check(nx,ny)){
            if(block[nx][ny]){
                if(visit[nx][ny]==0){
                    dfs(nx,ny,cnt);
                }
            }
        }
    }
    
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;
    
    N=table.size();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            block[i][j]=table[i][j];
            game[i][j]=game_board[i][j];
        }
    }
    int cnt=1;
    vector<vector<vector<int>>> A,B;
    vector<int> num_block;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visit[i][j])continue;
            if(block[i][j]){
                
                x1=x2=i;
                y1=y2=j;
                dfs(i,j,cnt);
                
                // int M = max(x2-x1+1,y2-y1+1);
                vector<vector<int>> V;
                V.resize(x2-x1+1);
                
                for(int a=x1;a<=x2;a++){
                    for(int b=y1;b<=y2;b++){
                        if(visit[a][b]==cnt){
                            V[a-x1].push_back(1);
                        }else{
                            V[a-x1].push_back(0);
                        }
                    }
                }
                A.push_back(V);
                cnt++;
            }
            
        }
    }
    cnt=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visit2[i][j])continue;
            if(!game[i][j]){
                x1=x2=i;
                y1=y2=j;
                count = 0;
                dfs2(i,j,cnt);
                num_block.push_back(count);
                
                vector<vector<int>> V;
                V.resize(x2-x1+1);
                
                for(int a=x1;a<=x2;a++){
                    for(int b=y1;b<=y2;b++){
                        if(visit2[a][b]==cnt){
                            V[a-x1].push_back(1);
                        }else{
                            V[a-x1].push_back(0);
                        }
                    }
                }
                B.push_back(V);
                cnt++;
            }
            
        }
    }
    
    bool visit3[A.size()];
    memset(visit3,false,sizeof(visit3));

    int total=0;
    int idx=-1;
    for(auto w:B){
        idx++;
        int nSize=w.size();
        int mSize=w[0].size();
        
        for(int i=0;i<A.size();i++){
            
//             nSize=A[i].size();
//             mSize=A[i][0].size();
//             cout << "@@" << endl;
//             for(int x=0;x<nSize;x++){
//                 for(int y=0;y<mSize;y++){
//                     cout << A[i][x][y] << " ";
//                 }
//                 cout << endl;
//             }
//             cout << endl;
//             for(int x=0;x<nSize;x++){
//                 for(int y=0;y<mSize;y++){
//                     cout << A[i][nSize-x-1][mSize-y-1] << " ";                   
//                 }
//                 cout << endl;
//             }
//             cout << "##" << endl;
            
//             cout << endl;
//             for(int x=0;x<mSize;x++){
//                 for(int y=0;y<nSize;y++){
//                     cout << A[i][nSize-y-1][x] << " ";
//                 }
//                 cout << endl;
//             }
            
//             for(int x=0;x<mSize;x++){
//                 for(int y=0;y<nSize;y++){
//                     cout << A[i][y][mSize-x-1] << " ";
//                 }
//                 cout << endl;
//             }
//             cout << endl;
            
            if(visit3[i])continue;
            int nSize2=A[i].size();
            int mSize2=A[i][0].size();
            if(nSize==nSize2 && mSize==mSize2){
                bool flag=true;
                for(int x=0;x<nSize;x++){
                    for(int y=0;y<mSize;y++){
                        if(w[x][y]!=A[i][x][y]){
                            flag=false;
                            break;
                        }
                    }
                    if(flag==false) break;
                }
                if(flag){
                    total+=num_block[idx];
                    visit3[i]=true;
                    break;
                }
                flag=true;
                for(int x=0;x<nSize;x++){
                    for(int y=0;y<mSize;y++){
                        if(w[x][y]!=A[i][nSize-x-1][mSize-y-1]){
                            flag=false;
                            break;
                        }
                    }
                    if(flag==false) break;
                }
                if(flag){
                    total+=num_block[idx];
                    visit3[i]=true;
                    break;
                }
            }
            if(nSize==mSize2 && mSize==nSize2){
                bool flag=true;
                for(int x=0;x<nSize;x++){
                    for(int y=0;y<mSize;y++){
                        if(w[x][y]!=A[i][y][nSize-x-1]){
                            flag=false;
                            break;
                        }
                    }
                    if(flag==false) break;
                }
                if(flag){
                    total+=num_block[idx];
                    visit3[i]=true;
                    break;
                }
                flag=true;
                for(int x=0;x<nSize;x++){
                    for(int y=0;y<mSize;y++){
                        if(w[x][y]!=A[i][mSize-y-1][x]){
                            flag=false;
                            break;
                        }
                    }
                    if(flag==false) break;
                }
                if(flag){                    
                    total+=num_block[idx];
                    visit3[i]=true;
                    break;
                }
            }
        }
    }
    
    
    
    return total;
}