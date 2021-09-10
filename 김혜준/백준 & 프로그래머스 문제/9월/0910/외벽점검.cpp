#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    sort(dist.begin(),dist.end(),cmp);
    
    for(int i=1;i<=dist.size();i++){
        //i명으로 가능한지 확인
        vector<int> temp; // 점검자
        for(int j=0;j<i;j++){
            temp.push_back(dist[j]);
        }
        sort(temp.begin(),temp.end());
        
        do{
            vector<int>wall;
        for(int j=0;j<weak.size();j++){
            wall.clear();
            for(int k=j;k<weak.size()+j;k++){
                if(k>=weak.size()) 
                    wall.push_back(weak[k%weak.size()]+n);
                else
                    wall.push_back(weak[k]);
            }
            
            int start=wall[0];
            int end=wall[wall.size()-1];
            
            int l=start,r;
            bool flag=false;
            int idx=0;
            
            for(int k=0;k<i;k++){
                r=l+temp[k];
                // cout << l << " " << r << endl;
                if(r>=end){ // 성공
                    flag=true;
                    break;
                }
                for(int z=idx;z<wall.size();z++){
                    if(wall[z]<=r){
                        continue;
                    }else{
                        idx=z+1;
                        l=wall[z];
                        break;
                    }
                }
            }
            
            if(flag){
                return i;
            }
        }
        }while(next_permutation(temp.begin(),temp.end()));
        
    }
    
    return -1;
}