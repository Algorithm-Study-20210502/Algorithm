#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    
    int answer = 0;
    
    set<int> s[9];
    
    s[1].insert(N);
    s[2].insert(N*11);
    s[3].insert(N*111);
    s[4].insert(N*1111);
    s[5].insert(N*11111);
    
    for(int i=2;i<=8;i++){
        for(int j=1;j<=i-1;j++){
            for(auto v:s[j]){
                for(auto w:s[i-j]){
                    s[i].insert(v*w);
                    s[i].insert(v+w);
                    if(v<w) continue;
                    s[i].insert(v-w);
                    if(w!=0)
                        s[i].insert(v/w);
                }
            }
        }
    }
    
    for(int i=1;i<=8;i++){
        for(auto w:s[i]){
            if(w==number){
                return i;
            }
        }
    }
    
    
    return -1;
}