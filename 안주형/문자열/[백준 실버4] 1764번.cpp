//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/1764
//  BOJ1764 듣보잡

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<string>noListen,noSee,ans;

    
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        noListen.push_back(s);
    }
    for (int i = 0; i < M; i++) {
        string s; cin >> s;
        noSee.push_back(s);
    }
    sort(noListen.begin(), noListen.end());
    sort(noSee.begin(), noSee.end());



    for (int i = 0; i < M; i++) {    //이진탐색
        int start = 0;
        int end = N - 1;
        string target = noSee[i];

        while (start <= end) {
            int mid = (start + end) / 2;
            if (target == noListen[mid]) { //찾는 값이 중앙값이면 출력
                ans.push_back(target);
                break;
            }
            else if (target > noListen[mid]) start = mid + 1;    //찾는 값이 중앙값 보다 더 클때 오른쪽 탐색
            else end = mid - 1;    //찾는 값이 중앙 값 보다 작을 때 왼쪽 탐색
        }
    }
    cout << ans.size() << "\n";
    for (string s : ans) {
        cout << s << "\n";
    }


}
