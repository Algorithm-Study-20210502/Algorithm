#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int visit[26];
    memset(visit,0,sizeof(visit));
    
    for(auto w:orders){
        for(int i=0;i<w.length();i++){
            visit[w.at(i)-'A']++;
        }
    }
    
    for(int i=0;i<course.size();i++){
        
        map<string,int>m;
        int maxN=0;
        vector<char> V;
        vector<int> K;
        for(int i=0;i<26;i++){
            if(visit[i]>=2){
                V.push_back('A'+i);
            }
        }
        
        int s = V.size();
        for(int a=0;a<s-course[i];a++){
            K.push_back(0);
        }
        for(int a=0;a<course[i];a++){
            K.push_back(1);
        }
        do{
            vector<char> temp;
            for(int i=0;i<s;i++){
                if(K[i]){
                    temp.push_back(V[i]);
                }
            }
            // for(auto w:temp)
            //     cout << w << " ";
            // cout << endl;
            int cnt=0;
            for(int j=0;j<orders.size();j++){
                bool flag=true;
                for(int k=0;k<temp.size();k++){
                    if(orders[j].find(temp[k])!=string::npos) continue;
                    else{
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    cnt++;
                }
            }
            if(cnt>=2){
                maxN=max(cnt,maxN);
                string sss="";
                for(int k=0;k<temp.size();k++){
                    sss.push_back(temp[k]);
                }
                m.insert({sss,cnt});
            }
        }while(next_permutation(K.begin(),K.end()));
        if(maxN<2) continue;
        for(auto w:m){
            if(w.second==maxN){
                answer.push_back(w.first);
            }
        }
        
    }
    sort(answer.begin(),answer.end());
    return answer;
}