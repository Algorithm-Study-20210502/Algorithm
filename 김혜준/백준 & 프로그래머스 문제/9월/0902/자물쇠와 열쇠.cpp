#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    int M = key.size();
    int N = lock.size();
    
    vector<int> arr1[M];
    vector<int> arr2[M];
    vector<int> arr3[M];
    vector<int> arr4[M];
    
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            arr1[i].push_back(key[i][j]);
        }
    }
    
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            arr2[i].push_back(key[M-1-j][i]);
        }
    }
    
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            arr3[i].push_back(key[M-1-i][M-1-j]);
        }
    }
    
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            arr4[i].push_back(key[j][M-1-i]);
        }
    }
    
    
    int lx=20,ly=20,rx=-1,ry=-1;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(lock[i][j]==0){
                lx=min(lx,i);
                ly=min(ly,j);
                rx=max(rx,i);
                ry=max(ry,j);
            }
        }
    }
    
    int dist_X = rx-lx+1;
    int dist_Y = ry-ly+1;
    
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            bool flag=true;
            if(i+dist_X-1<M&&j+dist_Y-1<M){
                // arr1[x][y] == lock[lx][ly]~lock[rx][ry]
                
                for(int x=0;x<dist_X;x++){
                    for(int y=0;y<dist_Y;y++){
                        if(arr1[i+x][j+y]==lock[lx+x][ly+y]){
                            flag=false;
                            break;
                        }
                    }
                }
                if(flag==true){
                    return true;
                }
            }
            
        }
    }
    
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            bool flag=true;
            if(i+dist_X-1<M&&j+dist_Y-1<M){
                for(int x=0;x<dist_X;x++){
                    for(int y=0;y<dist_Y;y++){
                        if(arr2[i+x][j+y]==lock[lx+x][ly+y]){
                            flag=false;
                            break;
                        }
                    }
                }
                if(flag==true){
                    return true;
                }
            }
            
        }
    }
    
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            bool flag=true;
            if(i+dist_X-1<M&&j+dist_Y-1<M){
                
                for(int x=0;x<dist_X;x++){
                    for(int y=0;y<dist_Y;y++){
                        if(arr3[i+x][j+y]==lock[lx+x][ly+y]){
                            flag=false;
                            break;
                        }
                    }
                }
                if(flag==true){
                    return true;
                }
            }
            
        }
    }
    
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            bool flag=true;
            if(i+dist_X-1<M&&j+dist_Y-1<M){
                for(int x=0;x<dist_X;x++){
                    for(int y=0;y<dist_Y;y++){
                        if(arr4[i+x][j+y]==lock[lx+x][ly+y]){
                            flag=false;
                            break;
                        }
                    }
                }
                if(flag==true){
                    return true;
                }
            }
            
        }
    }
    
    return false;
}