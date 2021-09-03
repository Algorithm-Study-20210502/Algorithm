#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize==0){
        return cities.size()*5;
    }
    
    map<string,int>m;
    queue<string> q;
    for(auto w:cities){
        transform(w.begin(),w.end(),w.begin(),::tolower);
        if(m[w]==1){
            answer+=1;
            
            // vector<string>temp;
            queue<string> temp;
            while(q.front()!=w){
                temp.push(q.front());
                q.pop();
            }
            q.pop();
            while(!q.empty()){
                temp.push(q.front());
                q.pop();
            }
            temp.push(w);
            q=temp;
        }else{
            answer+=5;
            if(q.size()==cacheSize){
                m[q.front()]=0;
                q.pop();
                q.push(w);
                m[w]=1;
            }else{
                q.push(w);
                m[w]=1;
            }
        }
    }
    
    return answer;
}