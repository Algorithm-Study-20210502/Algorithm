#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int>pool[24];
    for(int i=0;i<info.size();i++){
        string temp="";
        int a,b,c,d;
        int cnt=0;
        for(int j=0;j<info[i].length();j++){
            if(info[i][j]==' '){
                cnt++;
                // cout << temp << endl;
                if(cnt==1){
                    if(temp=="cpp"){
                        a=0;
                    }else if(temp=="java"){
                        a=1;
                    }else{
                        a=2;
                    }
                }
                else if(cnt==2){
                    if(temp=="backend"){
                        b=0;
                    }else{
                        b=1;
                    }
                }else if(cnt==3){
                    if(temp=="junior"){
                        c=0;
                    }else{
                        c=1;
                    }
                }else{
                    if(temp=="chicken"){
                        d=0;
                    }else{
                        d=1;
                    }
                }
                temp="";
            }else{
                temp.push_back(info[i][j]);
            }
            
        }
            int score=stoi(temp);
            int idx = a*8+b*4+c*2+d*1;
            pool[idx].push_back(score);
    }
    
    for(int i=0;i<query.size();i++){
        string str[5];
        int idx = query[i].find("and");
        
        for(int j=0;j<3;j++){
            str[j]=query[i].substr(0,idx-1);
            query[i] = query[i].substr(idx+4);
            idx = query[i].find("and");
        }
        idx = query[i].find(' ');
        str[3] = query[i].substr(0,idx);
        str[4] = query[i].substr(idx+1);
        int check_num = stoi(str[4]);
        int a,b,c,d;
        vector<int> calc[4];
        
        if(str[0]=="cpp"){
            calc[0].push_back(0);
        }else if(str[0]=="java"){
            calc[0].push_back(1);
        }else if(str[0]=="python"){
            calc[0].push_back(2);
        }else{
            calc[0].push_back(0);
            calc[0].push_back(1);
            calc[0].push_back(2);
        }
                 
         if(str[1]=="backend"){
                calc[1].push_back(0);
            }else if(str[1]=="frontend"){
                calc[1].push_back(1);
            }else{
                calc[1].push_back(0);
             calc[1].push_back(1);
         }
        
        if(str[2]=="junior"){
            calc[2].push_back(0);
        }else if(str[2]=="senior"){
            calc[2].push_back(1);
        }else{
            calc[2].push_back(0);
            calc[2].push_back(1);
        }
                 
        if(str[3]=="chicken"){
            calc[3].push_back(0);
        }else if(str[3]=="pizza"){
            calc[3].push_back(1);
        }else{
            calc[3].push_back(0);
            calc[3].push_back(1);
        }
        vector<int> check;
        for(int q=0;q<calc[0].size();q++){
            int a = calc[0][q];
            for(int w=0;w<calc[1].size();w++){
                int b= calc[1][w];
                for(int e=0;e<calc[2].size();e++){
                    int c=calc[2][e];
                    for(int r=0;r<calc[3].size();r++){
                        int d = calc[3][r];
                        check.push_back(a*8+b*4+c*2+d*1);
                    }
                }
            }
        }
        int ret=0;
        for(auto w:check){
            for(auto ww:pool[w]){
                if(ww>=check_num)
                    ret++;
            }
        }
        answer.push_back(ret);
        
     }
    
    
    
    return answer;
}