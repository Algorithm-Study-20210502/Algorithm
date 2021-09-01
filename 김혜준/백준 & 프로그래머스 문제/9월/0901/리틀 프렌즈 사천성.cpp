#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char arr[100][100];
vector<pair<int,int>> V[26];
bool visit[26];

bool check2(int x1,int y1,int x2,int y2,int n){
    char c = 'A'+n;
    bool flag=true;
    
    if(x1==x2){
        int minY=min(y1,y2);
        int maxY=max(y1,y2);
        
        for(int i=minY;i<=maxY;i++){
            // cout << arr[x1][i] << " " << c << endl;
            if(arr[x1][i]=='.'||arr[x1][i]==c){
                continue;
            }else{
                flag=false;
                break;
            }
        }
    }else{
        int minX=min(x1,x2);
        int maxX=max(x1,x2);
        
        for(int i=minX;i<=maxX;i++){
            // cout << arr[i][y1] << " " << c << endl;
            if(arr[i][y1]=='.'||arr[i][y1]==c){
                continue;
            }else{
                flag=false;
                break;
            }
        }
    }
    
    return flag;
}

bool check(int i){
    int sx = V[i][0].first;
    int sy = V[i][0].second;
    
    int ex = V[i][1].first;
    int ey = V[i][1].second;
    
    bool flag;
    // cout << sx << " " << sy << endl << ex << " " << ey << endl;
    
    if(check2(sx,sy,sx,ey,i)){
        if(check2(sx,ey,ex,ey,i)){
            arr[sx][sy]='.';
            arr[ex][ey]='.';
            visit[i]=true;
            return true;
        }
    }   
    // sx,sy->ex,sy->ex,ey
    if(check2(sx,sy,ex,sy,i)){
        if(check2(ex,sy,ex,ey,i)){
            arr[sx][sy]='.';
            arr[ex][ey]='.';
            visit[i]=true;
            return true;
        }
    }
    
    return false;
    
}

void init(){
    memset(visit,false,sizeof(visit));
    memset(arr,0,sizeof(arr));
    for(int i=0;i<26;i++)
        V[i].clear();
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";
    init();
    
    int total=0;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = board[i][j];
            if(arr[i][j]>='A'&&arr[i][j]<='Z'){
                V[arr[i][j]-'A'].push_back({i,j});
                total++;
            }
        }
    }
    total/=2;
    int cnt=0;
    
    while(1){ // 다 찾았거나 더이상 할수있는게 없으면 종료
        bool flag=false;
        for(int i=0;i<26;i++){
            if(V[i].size()==0)continue;
            if(visit[i])continue;
            char print = i+'A';
            if(check(i)){
                answer.push_back(i+'A');
                flag=true;
                cnt++;
                // if(cnt==total) return answer;
                break;
            }
        }
        if(cnt==total) break;
        if(flag==false){
            break;
        }
    }
    
    cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]>='A'&&arr[i][j]<='Z')
                cnt++;
        }
    }
    if(cnt) return "IMPOSSIBLE";
    
    return answer;
}