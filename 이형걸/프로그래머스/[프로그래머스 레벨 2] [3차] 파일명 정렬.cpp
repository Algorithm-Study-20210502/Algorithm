// stable_sort() : 정렬 기준에 따라 차이가 없다면 원래 입력에서 주어진 순서를 유지하는 정렬
// stoi() : stoi("000321abc000987") == 321

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compareAlpha(string a, string b);
bool compareNum(string a, string b);
int getNumIndex(string str);

vector<string> solution(vector<string> files) {   
    stable_sort(files.begin(), files.end(), compareNum);    
    stable_sort(files.begin(), files.end(), compareAlpha);

    return files;
}

bool compareAlpha(string a, string b) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    
    return a.substr(0, getNumIndex(a)) < b.substr(0, getNumIndex(b));
}

bool compareNum(string a, string b) {
    return stoi(a.substr(getNumIndex(a))) < stoi(b.substr(getNumIndex(b)));
}

int getNumIndex(string str) {    
    for(int i = 0; i < str.length(); ++i) {
        if(isdigit(str[i])) {
            return i;
        }
    }
}