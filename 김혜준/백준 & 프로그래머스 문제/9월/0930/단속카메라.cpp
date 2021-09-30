#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end(),cmp);
    int t=-30001;
    for(auto w : routes){
        // cout << w[0] << " "<< w[1] << endl;
        if(w[0]<=t) continue;
        answer++;
        t=w[1];
    }
    return answer;
}