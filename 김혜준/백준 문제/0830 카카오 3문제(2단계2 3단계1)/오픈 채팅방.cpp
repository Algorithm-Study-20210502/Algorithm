#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> m;
    string arr[100000][3];
    for(int i=0;i<record.size();i++){
        string act;
        string id;
        string name;
        int cnt=0;
        int idx1;
        for(int j=0;j<record[i].length();j++){
            if(record[i].at(j)==' '){
                cnt++;
                if(cnt==1){
                    act=record[i].substr(0,j);
                    idx1=j+1;
                    if(act=="Leave"){
                        id=record[i].substr(idx1,j-idx1);
                    }
                }else if(cnt==2){
                    id=record[i].substr(idx1,j-idx1);
                    name=record[i].substr(j+1,record[i].length()-j);
                }
            }
        }
        arr[i][0]=act;
        arr[i][1]=id;
        arr[i][2]=name;
        
        if(act=="Enter")
        {
             if(m.find(id)!=m.end()){
                m[id]=name;
            }else{
                m.insert({id,name});
            }
        }
        
        if(act=="Change"){
            // if(m.find(id)!=m.end()){
            m[id]=name;
            // }else{
            //     m.insert({id,name});
            // }
        }
        // cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << " " << endl;
    }
    
    for(int i=0;i<record.size();i++){
        string act = arr[i][0];
        string id = arr[i][1];
        string name = arr[i][2];
        
        string nickName;
        if(act=="Change") continue;
        
        if(m.find(id)!=m.end()){
            nickName = m[id];
        }else{
            nickName=name;
        }
        string s;
        if(act=="Enter"){
            s = nickName.append("님이 들어왔습니다.");
        }else if(act=="Leave"){
            s = nickName.append("님이 나갔습니다.");
        }
        answer.push_back(s);
    }
    
    
    
    return answer;
}