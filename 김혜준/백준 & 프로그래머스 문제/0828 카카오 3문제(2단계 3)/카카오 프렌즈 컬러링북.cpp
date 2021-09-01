#include <vector>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int arr[100][100];
bool visit[100][100];

int dx[4];
int dy[4];

int X,Y;
int ret,cnt;

//ret는 가장 큰 영역,cnt는 몇개의 영역
void search(int,int);
bool check(int,int);
void init(int,int);

bool check(int x, int y){
    if(x>=0&&x<X&&y>=0&&y<Y)
        return true;
    return false;
}

void init(int m,int n){
    X=m;
    Y=n;
    ret=0;
    cnt=0;
    dx[0]=-1;
    dx[1]=1;
    dx[2]=0;
    dx[3]=0;
    dy[0]=0;
    dy[1]=0;
    dy[2]=-1;
    dy[3]=1;
    memset(visit,false,sizeof(visit));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]==false&&arr[i][j]!=0){
                search(i,j);
                cnt++;
            }
        }
    }
}

void search(int x,int y){
    int total =0;
    visit[x][y]=true;
    int num=arr[x][y];
    
    queue<pair<int,int>> q;
    q.push({x,y});
    total++;
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            
            if(check(nx,ny)){
                if(arr[nx][ny]==num){
                    if(visit[nx][ny]==false){
                        visit[nx][ny]=true;
                        q.push({nx,ny});
                        total++;
                    }
                }    
            }
        }
    }
    // cout << total << endl;
    ret=max(ret,total);
    
    
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=picture[i][j];
        }
    }
    init(m,n);

    vector<int> answer(2);
    answer[0] = cnt;
    answer[1] = ret;
    return answer;
}