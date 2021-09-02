#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> combination(string input, int r) {
    int n = (int)input.size();
    if (n < r || r < 0) return {};
    vector<string>res;
    string tmp;
    tmp.resize(r);
    
    vector<bool> per(n);
    fill(per.end() - r, per.end(), 1);
    
    do {
        int cur = 0;
        for (int i = 0; i < n; ++i)
            if (per[i]) tmp[cur++] = input[i];
        res.emplace_back(tmp);
    } while (next_permutation(per.begin(), per.end()));
    return res;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<map<string,int>>menu(course.size());
    vector<int> max_val(course.size());
    vector<string> answer;
    for (auto &str : orders) {
        sort(str.begin(), str.end());
        for (int k = 0; k < course.size();k++) {
            if (course[k] > str.size())break;
            auto comb = combination(str, course[k]);
            for (auto &t : comb) {
                auto res = menu[k].insert({ t, 1 });
                if (!res.second) {
                    res.first->second++;
                    max_val[k] = max_val[k] < res.first->second ? res.first->second : max_val[k];
                }
                
            }
        }
    }
    for (int i = 0; i < course.size(); i++) {
        for (auto &t : menu[i]) {
            if (t.second == max_val[i])
                answer.emplace_back(t.first);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}

