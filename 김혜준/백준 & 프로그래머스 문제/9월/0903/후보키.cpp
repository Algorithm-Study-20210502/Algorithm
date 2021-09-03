#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> ckV;

bool checkStr(string s){
    cout <<"@"<< s << endl;
    for(auto w:ckV){
        bool flag=false;
        for(int i=0;i<w.length();i++){
            if(s.find(w[i])==string::npos){
                flag=true;
                break;
            }
        }
        if(flag==false){
            return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    bool visit[8];
    memset(visit,false,sizeof(visit));
    
    map<string,int>m;
    
    int X = relation[0].size();
    int Y = relation.size();
    
    for(int i=1;i<=X;i++){
        vector<int> V;
        vector<int> K;
        int cnt=0;
        for(int j=0;j<X;j++){
            V.push_back(j);
        }
        for(int j=0;j<X-i;j++){
            K.push_back(0);
        }
        
        for(int j=0;j<i;j++){
            K.push_back(1);
        }
        
        do{
            vector<int> f;
            string check="";
            for(int j=0;j<X;j++){
                if(K[j]){
                    f.push_back(V[j]);
                    check.append(to_string(V[j]));
                }
            }
            if(!checkStr(check)) continue;
            map<string,int>m;
            bool flag=true;
            for(int k=0;k<Y;k++){
                string temp="";
                for(int j=0;j<f.size();j++){
                    temp.append(relation[k][f[j]]);
                }
                if(m.find(temp)!=m.end()){
                    //있으면
                    flag=false;
                    break;
                }else{
                    // cout << temp << endl;
                    m.insert({temp,1});
                }
            }
            if(flag){
                string visitStr = "";
                for(int j=0;j<f.size();j++){
                    visitStr.append(to_string(V[f[j]]));
                }
                ckV.push_back(visitStr);
                answer++;
            }
        }while(next_permutation(K.begin(),K.end()));
    }
    cout <<"#";
    for(auto w:ckV)
        cout << w << endl;
    
    return answer;
}
