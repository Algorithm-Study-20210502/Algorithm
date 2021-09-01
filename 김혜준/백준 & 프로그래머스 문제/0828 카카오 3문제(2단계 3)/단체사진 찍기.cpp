#include <string>
#include <vector>
#include <algorithm>

using namespace std;



bool check(string s,char m,char n,char num,char dir){
    int N = num-'0';
    int midx,nidx;
    
    for(int i=0;i<s.length();i++){
        if(s.at(i)==m){
            midx=i;
        }
        if(s.at(i)==n){
            nidx=i;
        }
    }
    
    int ret = abs(midx-nidx)-1;
    
    switch(dir){
        case '>':
            return ret > N;
            break;
        case '<':
            return ret < N;
            break;
        case '=':
            return ret == N;
            break;
    }
    
    
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector <int> v;
    vector <char> friends;
    for(int i=0;i<8;i++){
        v.push_back(i);
    }
    friends.push_back('A');
    friends.push_back('C');
    friends.push_back('F');
    friends.push_back('J');
    friends.push_back('M');
    friends.push_back('N');
    friends.push_back('R');
    friends.push_back('T');
    
    do{
        string s="";
        for(int i=0;i<8;i++){
            s.push_back(friends[v[i]]);
        }

        bool flag=true;
        for(int i=0;i<n;i++){
            string k = data[i];
            if(!check(s,k.at(0),k.at(2),k.at(4),k.at(3))){
                flag=false;
                break;
            }
        }
        if(flag) answer++;
        
    }while(next_permutation(v.begin(),v.end()));
    
    return answer;
}