#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct info{
    string HEAD;
    int NUMBER;
    // string TAIL;
    int idx;
}info;

bool cmp(info a,info b){
    if(a.HEAD!=b.HEAD){
        return a.HEAD < b.HEAD;
    }else{
        
        if(a.NUMBER!=b.NUMBER)
            return a.NUMBER<b.NUMBER;
        else{
            return a.idx<b.idx;
        }
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    int cnt=0;
    
    vector<info> V;
    
    for(auto w:files){
        
        info cur;
        string temp = "";
        bool headFlag=true;
        bool numFlag=false;
        for(int i=0;i<w.length();i++){
            if(headFlag){
                if(w[i]>='0'&&w[i]<='9'){
                    headFlag=false;
                    numFlag=true;
                    transform(temp.begin(),temp.end(),temp.begin(),::tolower);
                    cur.HEAD=temp;
                    temp="";
                    temp+=w[i];
                }else{
                    temp+=w[i];
                    
                }
            }else if(numFlag){
                if(w[i]>='0'&&w[i]<='9'){
                    
                    temp+=w[i];
                    if(temp.length()==5){
                        cur.NUMBER=stoi(temp);
                        numFlag=false;
                        temp="";
                        break;
                    }
                }else{
                    cur.NUMBER=stoi(temp);
                    numFlag=false;
                    temp="";
                    temp+=w[i];
                    break;
                }
            }else{
                temp+=w[i];
                break;
            }
        }
        if(numFlag)cur.NUMBER=stoi(temp);
        cur.idx=cnt++;
        cout << cur.idx << " " << cur.HEAD << " " << cur.NUMBER << endl;
        V.push_back(cur);
    }
    sort(V.begin(),V.end(),cmp);
    for(int i=0;i<V.size();i++){
        answer.push_back(files[V[i].idx]);
    }
    return answer;
}