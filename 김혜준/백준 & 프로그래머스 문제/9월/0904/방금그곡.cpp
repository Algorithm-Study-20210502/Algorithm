#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct info{
    int id;
    int s;
    int e;
    int time;
    string title;
    string music;
}info;

bool cmp(info a,info b){
    if(a.time!=b.time)
        return a.time>b.time;
    return a.id<b.id;
}

bool check(string s,string m){
    while(s.find(m)!=string::npos){
        int idx = s.find(m)+m.length();
        cout << idx << endl;
        if(idx==s.length()) return true;
        if(s.at(idx)=='#')
        {
            s=s.substr(idx-m.length()+1);
            if(s[0]=='#')
                s=s.substr(1);
        }else{
            return true;
        }
        cout << s << endl;
    }
    return false;
}

string solution(string m, vector<string> v) {
    string answer = "";
    vector<info>ret;
    int cnt=0;
    for(auto w:v){
        cnt++;
        string start="";
        string end="";
        string title="";
        int idx1=w.find(',');
        start = w.substr(0,idx1);
        w=w.substr(idx1+1);
        idx1 = w.find(',');
        end = w.substr(0,idx1);
        w=w.substr(idx1+1);
        
        idx1 = w.find(',');
        title = w.substr(0,idx1);
        w = w.substr(idx1+1);
        
        string sh = start.substr(0,2);
        string sm = start.substr(3,2);
        
        string eh = end.substr(0,2);
        string em = end.substr(3,2);
        
        int S = stoi(sh)*60+stoi(sm);
        int E = stoi(eh)*60+stoi(em);
        
        int all = E-S;
        
        string temp="";
        int j=0;
        for(int i=0;i<all;i++){
            temp.push_back(w[j%w.length()]);
            if(w[(j+1)%w.length()]=='#')
            {
                temp.push_back('#');
                j++;
            }
            j++;
        }
        
        info cur;
        cur.id=cnt;
        cur.s=S;
        cur.e=E;
        cur.time=all;
        cur.title=title;
        cur.music = temp;
        ret.push_back(cur);
        cout << title << endl;
        cout << temp << endl;
    }
    
    sort(ret.begin(),ret.end(),cmp);
    for(auto w:ret){
        // cout << w.music << endl;
        string temp = w.music;
        if(check(temp,m)){
            return w.title;
        }
    }
    return "(None)";
}