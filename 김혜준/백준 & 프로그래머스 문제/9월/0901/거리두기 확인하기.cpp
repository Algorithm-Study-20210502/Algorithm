#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx1[4]={-1,0,1,0};
int dy1[4]={0,1,0,-1};
int dx2[4]={-2,0,2,0};
int dy2[4]={0,2,0,-2};

int dx3[4]={-1,1,-1,1};
int dy3[4]={1,-1,-1,1};
int dx4[8]={-1,0,1,0,-1,0,1,0};
int dy4[8]={0,1,0,-1,0,-1,0,1};

char arr[5][5][5];

bool check2(int x,int y){
    if(x>=0&&x<5&&y>=0&&y<5)
        return true;
    return false;
}

bool check(int n,int x,int y){ // 거리두기를 안지키면 true return
    
    // 거리가 1일 때
    for(int i=0;i<4;i++){
        int nx=x+dx1[i];
        int ny=y+dy1[i];
        if(check2(nx,ny)){
            if(arr[n][nx][ny]=='P')
                return true;
        }
    }
    
    // 거리가 2일 때 
    
    for(int i=0;i<4;i++){
        int nx=x+dx2[i];
        int ny=y+dy2[i];
        
        int cx=x+dx1[i];
        int cy=y+dy1[i];
        if(check2(nx,ny)){
            if(arr[n][nx][ny]=='P'){
                char c = arr[n][cx][cy];
                if(c=='O')
                    return true;
            }
        }
    }
    
    for(int i=0;i<4;i++){
        int nx=x+dx3[i];
        int ny=y+dy3[i];
        
        int cx1=x+dx4[i*2];
        int cy1=y+dy4[i*2];
        
        int cx2=x+dx4[i*2+1];
        int cy2=y+dx4[i*2+1];
        
        if(check2(nx,ny)){
            if(arr[n][nx][ny]=='P'){
                char c1 = arr[n][cx1][cy1];
                char c2 = arr[n][cx2][cy2];
                
                if(c1=='O'||c2=='O'){
                    return true;
                }
            }
        }
    }
    
    return false;
    
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int k=0;k<places.size();k++){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                arr[k][i][j]=places[k][i][j];
            }
        }
        
    }
    
    for(int k=0;k<places.size();k++){
        bool flag=false;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(places[k][i][j]=='P'){
                    if(check(k,i,j)){
                        // cout << places[k][i][j] << "   ";
                        // cout << k << i << j << endl;
                        flag=true;
                        break;
                    }
                }
            }
            if(flag)break;
        }
        if(flag)answer.push_back(0);
        else answer.push_back(1);
    }
    
    return answer;
}