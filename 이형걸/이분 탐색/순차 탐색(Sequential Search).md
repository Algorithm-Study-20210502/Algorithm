# 순차 탐색(Sequential Search)

리스트 안에 있는 특정한 데이터를 찾기 위해 앞에서부터 데이터를 하나씩 차례대로 확인하는 방법

## 특징

- 순차 탐색은 이름처럼 순차로 데이터를 탐색한다는 의미

- 보통 **`정렬되지 않은 데이터`** 를 찾기 위해 **앞에서부터 하나씩 차례대로 확인** 하는 방법

- **데이터 정렬 여부와 상관없이** 가장 앞에 있는 원소부터 하나씩 확인해야 한다.

## 구현법

```c++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 순차 탐색 소스코드 구현
int sequantialSearch(int n, string target, vector<string> arr) {
    // 각 원소를 하나씩 확인하며
    for (int i = 0; i < n; i++) {
        // 현재의 원소가 찾고자 하는 원소와 동일한 경우
        if (arr[i] == target) {
            return i + 1; // 현재의 위치 반환 (인덱스는 0부터 시작하므로 1 더하기)
        }
    }
    return -1; // 원소를 찾지 못한 경우 -1 반환
}

int n; // 원소의 개수
string target; // 찾고자 하는 문자열
vector<string> arr;

int main(void) {
    cout << "생성할 원소 개수를 입력한 다음 한 칸 띄고 찾을 문자열을 입력하세요." << '\n';
    cin >> n >> target;
    
    cout << "앞서 적은 원소 개수만큼 문자열을 입력하세요. 구분은 띄어쓰기 한 칸으로 합니다." << '\n';
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        arr.push_back(x);
    }

    // 순차 탐색 수행 결과 출력
    cout << sequantialSearch(n, target, arr) << '\n';
}
```

## 시간 복잡도

데이터의 개수가 N개일 때 최대 N번의 비교 연산이 필요하므로 순차 탐색의 시간 복잡도는 `O(N)` 이다.

## 활용

- 리스트에 특정 값의 원소가 있는지 체크

- 리스트 자료형에서 특정한 값을 가지는 원소의 개수를 세는 count() 메서드 