#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for(int i = 0; i < triangle.size(); ++i) {
        for(int j = 0; j < triangle[i].size(); ++j) {
            int left, right;
            
            if(j - 1 < 0) {
                left = 0;
            }
            else {
                left = triangle[i-1][j-1];
            }
            if(j == triangle[i].size()-1) {
                right = 0;
            }
            else {
                right = triangle[i-1][j];
            }
            
            triangle[i][j] = triangle[i][j] + max(left, right);
        }
    }
    
    for(int i = 0; i < triangle.size(); ++i) {
        answer = max(answer, triangle[triangle.size()-1][i]);
    }
    
    return answer;
}