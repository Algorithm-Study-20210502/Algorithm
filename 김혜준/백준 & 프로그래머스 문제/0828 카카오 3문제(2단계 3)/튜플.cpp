#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(vector<int> v1,vector<int> v2){
    return v1.size()<v2.size();
}

vector<int> solution(string s) {
    bool visit[100001];
    memset(visit,false,sizeof(visit));
    vector<int> answer;
    
    vector<vector<int>> V;
    
    string temp;
    vector<int> v;
    for(int i=1;i<s.length()-1;i++){
        if(s.at(i)=='{'){
            v.clear(); 
            temp="";
        }
        if(s.at(i)==','){
             v.push_back(stoi(temp));
            temp="";
        }
        if(s.at(i)>='0'&&s.at(i)<='9'){
            temp.push_back(s.at(i));
        }
        if(s.at(i)=='}'){
            v.push_back(stoi(temp));
            V.push_back(v);
        }
        
    }
    sort(V.begin(),V.end(),cmp);
    
    for(int i=0;i<V.size();i++){
        for(auto w:V[i]){
            if(visit[w]==false){
                visit[w]=true;
                answer.push_back(w);
            }
        }
    }
    
    return answer;
}