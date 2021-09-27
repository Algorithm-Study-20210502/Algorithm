#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string,int> a, pair<string,int> b){
    return a.second>b.second;
}

bool cmp2(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }else{
        return a.first>b.first;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<string,int>> temp;
    map<string,int> m;
    map<string,int> M;
    vector<pair<int,int>> V[101];
    int cnt=1;
    for(int i=0;i<genres.size();i++){
        m[genres[i]]+=plays[i];
        if(M[genres[i]]==0){
            M[genres[i]]=cnt++;
        }
        V[M[genres[i]]].push_back({plays[i],i});
    }
    
    for(int i=0;i<genres.size();i++){
        if(m[genres[i]]>0){
            temp.push_back({genres[i],m[genres[i]]});
            m[genres[i]]=0;
        }
    }
    
    sort(temp.begin(),temp.end(),cmp);
    for(int i=1;i<cnt;i++){
        sort(V[i].begin(),V[i].end(),cmp2);
    }
    
    for(auto w:temp){
        answer.push_back(V[M[w.first]][0].second);
        if(V[M[w.first]].size()>1)
            answer.push_back(V[M[w.first]][1].second);
    }
    
    return answer;
}