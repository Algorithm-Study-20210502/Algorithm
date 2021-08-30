#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(vector<string> lines) {
    vector<pair<double,double>> ret;
    for(auto w:lines){
        
        double h=stod(w.substr(11,2));
        double m=stod(w.substr(14,2));
        double s=stod(w.substr(17,2));
        double ms=stod(w.substr(20,3))/1000;
        
        string temp = w.substr(24,w.length()-24);
        double run = stod(temp);
        
        double endTime = (h*3600)+(m*60)+(s)+ms;
        double startTime = endTime-run+0.001;
        ret.push_back({startTime,endTime});
    }
    int ans=0;
    for(int i=0;i<lines.size();i++){
        double s=ret[i].second;
        int cnt=1;
        for(int j=i+1;j<lines.size();j++){
            if(s+1>ret[j].first){
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    return ans;
}