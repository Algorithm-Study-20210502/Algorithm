#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> temp;

int dx[4]={1,0,1};
int dy[4]={0,1,1};
int ret;
int m,n;

void PRINT(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
}

int search(){
    // PRINT();
    vector<pair<int,int>> del;
    int cnt=0;
    for(int i=0;i<m-1;i++){
        for(int j=0;j<n-1;j++){
            int x=i;
            int y=j;
            bool flag=true;
            for(int k=0;k<3;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if(temp[x][y]!=temp[nx][ny]){
                    flag=false;
                    break;
                }
            }
            if(flag&&temp[x][y]!=' '){
                cnt++;
                del.push_back({x,y});
                for(int k=0;k<3;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    del.push_back({nx,ny});
                }
            }
        }
    }
    
    for(auto w:del){
        int x = w.first;
        int y = w.second;
        if(temp[x][y]!=' ')
        {
            // cout << x <<" " <<y << endl;
            temp[x][y]=' ';
            ret++;
        }
    }
    // cout <<"@@"<< cnt << endl;
    return cnt;
}

void down(){
    // PRINT();
    for(int i=0;i<n;i++){
        for(int j=m-1;j>=0;j--){
            if(temp[j][i]==' '){
                for(int k=j-1;k>=0;k--){
                    if(temp[k][i]!=' '){
                        // cout <<"@"<< temp[k][i] << endl;
                        temp[j][i]=temp[k][i];
                        temp[k][i]=' ';
                        break;
                    }
                }
            }
        }
    }
    // PRINT();
}

int solution(int M, int N, vector<string> board) {
    ret=0;
    m=M;
    n=N;
    for(int i=0;i<m;i++){
        temp.push_back(board[i]);
    }
    int i=0;
    while(search()!=0){
        down();
    }
    
    
    
    return ret;
}