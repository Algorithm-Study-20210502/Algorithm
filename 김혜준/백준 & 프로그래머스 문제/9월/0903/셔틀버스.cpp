#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    // m*n 번째 승객이 되어야 함!
    vector<int>V;
    for(auto w:timetable){
        string h = w.substr(0,2);
        string m = w.substr(3,2);
        
        int H = stoi(h);
        int M = stoi(m);
        
        V.push_back((H*60+M));
    }
    sort(V.begin(),V.end());
    
    int start = 540;
    int idx=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int cur = start + t*(i-1);
        cout << cur << endl;
        int bb=0;
        for(int j=0;j<m;j++){
            if(idx==V.size())break;
            if(V[idx]<=cur){
                cnt++;
                idx++;
                bb++;
            }else{
                break;
            }
        }
        if(i==n){
            cout << cur << endl;
            cout << bb << "@";
            if(bb<m){
                
                int h=cur/60;
                int m=cur%60;
                string sh = to_string(h);
                string sm = to_string(m);
                cout << sh << " " << sm;
                if(sh.length()==1){
                    sh="0"+sh;
                }
                if(sm.length()==1){
                    sm="0"+sm;
                }
                
                answer.append(sh);
                answer.push_back(':');
                answer.append(sm);
            }else{
                cur = V[idx-1]-1;
                int h=cur/60;
                int m=cur%60;
                string sh = to_string(h);
                string sm = to_string(m);
                
                if(sh.length()==1){
                    sh="0"+sh;
                }
                if(sm.length()==1){
                    sm="0"+sm;
                }
                cout << sh << " " << sm;
                answer.append(sh);
                answer.push_back(':');
                answer.append(sm);
            }
        }
    }
        
    return answer;
}