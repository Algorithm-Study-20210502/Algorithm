#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string,string>parent;
map<string,int>sell;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i=0;i<enroll.size();i++){
        parent[enroll[i]]=referral[i];
    }
    
    for(int i=0;i<seller.size();i++){
        string cur = seller[i];
        int money = amount[i]*100;
        
        while(money!=0){
            if(cur=="-"){
                sell[cur]+=money;
                break;
            }
            // cout << money << " " << money*0.9 << endl;
            if(money/10!=0)
                sell[cur]+=money-money/10;
            else
                sell[cur]+=money;
            // cout << cur << " " << sell[cur] << endl;
            money/=10;
            cur = parent[cur];
        }
    }
    
    for(int i=0;i<enroll.size();i++){
        string cur = enroll[i];
        answer.push_back(sell[cur]);
    }
    
    
    
    return answer;
}