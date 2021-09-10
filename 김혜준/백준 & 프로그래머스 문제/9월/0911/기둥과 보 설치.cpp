#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a,vector<int> b){
    int ax=a[0];
    int ay=a[1];
    int at=a[2];
    
    int bx=b[0];
    int by=b[1];
    int bt=b[2];
    
    if(ax!=bx) return ax<bx;
    if(ay!=by) return ay<by;
    if(at==0) return true;
    return false;
}

int arr1[101][101]; // 기둥
int arr2[101][101];
int N;

bool check(){
    
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(arr1[i][j]==1){
                if(j==0) continue;
                if(arr2[i][j]==1||arr2[i-1][j]==1) continue;
                return false;
            }
        }
    }
    
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(arr2[i][j]==1){
                if(arr2[i-1][j]==1&&arr2[i+1][j]==1) continue;
                if(arr1[i][j]>=2||arr1[i+1][j]>=2) continue;
                return false;
            }
        }
    }
    return true;
}

void make(int x, int y, int t){ // t를 설치
    
    if(t==0){
        if(y==0){ // 바닥에
            arr1[x][y]+=1;
            arr1[x][y+1]+=2;
        }else{
            if(arr2[x][y]==1||arr2[x-1][y]==1){ // 보 위에
                arr1[x][y]+=1;
                arr1[x][y+1]+=2;
            }else if(arr1[x][y]==2){ // 기둥 위에
                arr1[x][y]+=1;
                arr1[x][y+1]+=2;
            }
        }
    }else{
        if(arr1[x][y]>=2 || arr1[x+1][y]>=2){ // 기둥 위
            arr2[x][y]+=1;
            // arr2[x+1][y]+=1;
        }else if(arr2[x-1][y]==1&&arr2[x+1][y]==1){
            arr2[x][y]+=1;
            // arr2[x+1][y]+=1;
        }
    }
}

void vanish(int x,int y,int t){
    if(t==0){
        arr1[x][y]-=1;
        arr1[x][y+1]-=2;
        
        if(check()) return;
        
        arr1[x][y]+=1;
        arr1[x][y+1]+=2;
    }else{
        arr2[x][y]-=1;
        // arr2[x+1][y]-=1;
        
        if(check())return;
        
        arr2[x][y]+=1;
        // arr2[x+1][y]+=1;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N=n;
    // x,y, a(0은 기둥 1은 보) ,b(0은 삭제 1은 설치)
    // 기둥은 바닥 위,보의 한쪽 끝부분 위,다른 기둥위에 있을 수 있음
    // 보는 한쪽 끝부분이 기둥위에 있거나 양쪽 끝부분이 다른 보와 동시에 연결되어 있어야함
    memset(arr1,0,sizeof(arr1));
    memset(arr2,0,sizeof(arr2));
    
    for(auto w:build_frame){
        int x = w[0];
        int y = w[1];
        int a = w[2];
        int b = w[3];
        
        // arr[y][x];
        
        if(b==0){ // 삭제 하는 경우
            vanish(x,y,a);
        }else{ // 설치 하는 경우
            make(x,y,a);
            
        }
//         cout << x << " "<< y << " "<< a << " " << b<< endl;
//         for(int i=0;i<=n;i++){
//             for(int j=0;j<=n;j++){
//                 cout << arr1[i][j] << " ";
//             }
//             cout << endl;
//         }

//         cout << endl;

//         for(int i=0;i<=n;i++){
//             for(int j=0;j<=n;j++){
//                 cout << arr2[i][j] << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
        
    }
    
    
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(arr1[j][i]==1){
                vector<int>temp;
                temp.push_back(j);
                temp.push_back(i);
                temp.push_back(0);
                arr1[j][i]-=1;
                arr1[j][i+1]-=2;
                answer.push_back(temp);
            }
        }   
    }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(arr2[j][i]==1){
                vector<int>temp;
                temp.push_back(j);
                temp.push_back(i);
                temp.push_back(1);
                arr2[j][i]-=1;
                // arr2[j+1][i]-=1;
                answer.push_back(temp);
                // temp.clear();
                // temp.push_back(j+1);
                // temp.push_back(i);
                // temp.push_back(1);
                // answer.push_back(temp);
            }
        }
    }
    
    sort(answer.begin(),answer.end(),cmp);
    return answer;
}