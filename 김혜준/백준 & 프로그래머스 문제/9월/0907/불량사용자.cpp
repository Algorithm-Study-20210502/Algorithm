#include <string>
#include <vector>
#include <iostream>
#include <map>
#include<algorithm>

using namespace std;

vector<vector<string>> V[8];
int answer = 0;
int N;
map<string,int> m,M;
vector<int>ret;
vector<vector<int>>R;
map<string,int> AN;

bool check(string s,string ban){
    if(s.length()!=ban.length()) return false;
    
    for(int i=0;i<s.length();i++){
        if(ban[i]=='*') continue;
        if(s[i]!=ban[i]) return false;
    }
    return true;
}

void dfs(int n){
    
    if(n==N){
        R.push_back(ret);
        return;
    }
    
    for(auto w:V[n]){
        for(auto v:w){
            if(M[v])continue;
            M[v]++;
            ret.push_back(m[v]);
            dfs(n+1);
            M[v]--;
            ret.pop_back();
        }
    }
}

void last(){
    
    for(int i=0;i<R.size();i++){
        string temp="";
        sort(R[i].begin(),R[i].end());
        for(auto w:R[i]){
            temp.push_back(w+'0');
        }
        // cout << temp << " ";
        if(AN[temp]==0)answer++;
        AN[temp]++;
        temp="";
    }
    
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    N=banned_id.size();
    cout << N << endl;
    
    for(int i=0;i<user_id.size();i++){
        m.insert({user_id[i],i});
    }
    
    for(int j=0;j<banned_id.size();j++){
        vector<string>temp;
        for(int i=0;i<user_id.size();i++){
            if(check(user_id[i],banned_id[j])){
                temp.push_back(user_id[i]);
            }
        }
        V[j].push_back(temp);
    }
    
    dfs(0);
    last();
    return answer;
}