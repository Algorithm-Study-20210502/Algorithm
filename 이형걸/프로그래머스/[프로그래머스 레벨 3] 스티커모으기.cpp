#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll solution(vector<int> sticker) {
    ll answer = 0, even = 0, odd = 0, size = sticker.size();
    
    for(int i = 0; i < size; ++i) {
        if((i+1)%2) {
            odd += (ll)sticker[i];
        }
        else {
            even += (ll)sticker[i];
        }
    }
    
    if(size%2) {
        answer = max(answer, max(even, odd-sticker[size-1]));
        answer = max(answer, odd-sticker[0]);
    }
    else {
        answer = max(answer, max(even, odd));
    }
    
    return answer;
}