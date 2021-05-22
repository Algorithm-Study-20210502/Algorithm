# 이분 탐색(Binary Search) : 범위를 반씩 좁혀가는 탐색

범위를 반으로 쪼개면서 탐색하는 알고리즘

## 특징

- 배열 내부의 `데이터가 정렬` 되어 있어야만 사용할 수 있는 알고리즘

- 데이터가 무작위일 때는 사용할 수 없지만, 이미 정렬되어 있다면 매우 빠르게 찾을 수 있다는 특징

- **탐색 범위를 절반씩 좁혀가며 데이터를 탐색** 하는 특징 

## 구현볍

`위치를 나타내는 변수 3개` 를 사용

- **시작점, 끝점, 중간점**

- **찾으려는 데이터(target)와 중간점(middle) 위치에 있는 데이터를 반복적으로 비교** 
  
  - 중간점이 실수일 때는 **소수점 이하를 버린다.** 

1. 재귀 함수를 이용하는 방법

```c++
#include <iostream>
#include <vector>

int n, target;
vector<int> arr;

int binarySearch(vector<int>& arr, int target, int start, int end); 

int main(void) {
    // n(원소의 개수)와 target(찾고자 하는 값)을 입력받기 
    cin >> n >> target;
    // 전체 원소 입력받기 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // 이진 탐색 수행 결과 출력 
    int result = binarySearch(arr, target, 0, n - 1);
    if (result == -1) {
        cout << "원소가 존재하지 않습니다." << '\n';
    }
    else {
        cout << result + 1 << '\n';
    }
}

// 이진 탐색 소스코드 구현(재귀 함수)
int binarySearch(vector<int>& arr, int target, int start, int end) {
    if(start > end) {
        return -1;
    }

    int mid = (start + end) / 2; 
    
    // 찾은 경우 중간점 인덱스 반환
    if(arr[mid] == target) {
        return mid;
    }
    // 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
    else if(arr[mid] > target) {
        return binarySearch(arr, target, start, mid - 1);
    }
    // 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
    else {
        return binarySearch(arr, target, mid + 1, end);
    }
}
```
2. 반복문을 이용하는 방법

```c++
#include <iostream>
#include <vector>

using namespace std;

int n, target;
vector<int> arr;

int binarySearch(vector<int>& arr, int target, int start, int end);

int main(void) {
    // n(원소의 개수)와 target(찾고자 하는 값)을 입력 받기 
    cin >> n >> target;
    // 전체 원소 입력 받기 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // 이진 탐색 수행 결과 출력 
    int result = binarySearch(arr, target, 0, n - 1);
    if (result == -1) {
        cout << "원소가 존재하지 않습니다." << '\n';
    }
    else {
        cout << result + 1 << '\n';
    }
}

// 이진 탐색 소스코드 구현(반복문)
int binarySearch(vector<int>& arr, int target, int start, int end) {
    while(start <= end) {
        int mid = (start + end) / 2;

        // 찾은 경우 중간점 인덱스 반환
        if(arr[mid] == target) {
            return mid;
        }

        // 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
        else if(arr[mid] > target) {
            end = mid - 1;
        }

        // 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
        else {
            start = mid + 1;
        }
    } 

    return -1;
}

```

## 시간 복잡도

이진 탐색은 한 번 확인할 때마다 **확인하는 원소의 개수가 절반씩 줄어든다** 는 점에서 시간복잡도가 `O(logN)` 이다.

- 절반씩 데이터를 줄어들도록 만든다는 점에서 `퀵 정렬` 과 공통점이 있다.

- 한 단계를 거칠 때마다 데이터의 범위가 평균적으로 절반으로 줄어든다.

- 단계마다 2로 나누는 것과 동일, 연산 횟수는 Olog2N 에 비례, 빅오 표기법에 따라 O(logN)  

## 활용

이진 탐색은 코딩 테스트에서 **단골**로 나오는 문제이니 **가급적 외우길 권장한다.**

이진 탐색의 원리는 다른 알고리즘에서도 폭넓게 적용되는 원리와 유사하기 때문에 매우 중요하다.

높은 난이도의 문제에서는 이진 탐색 알고리즘이 다른 알고리즘과 함께 사용되기도 한다.

- **탐색 범위가 큰 상황에서의 탐색** 을 가정하는 문제가 많다.
  
  - 처리해야 할 데이터의 개수나 값이 `10,000,000(1000만) 단위 이상` 으로 넘어가면 `이진 탐색과` 같이 `O(logN)` 의 속도를 내야 하는 알고리즘을 떠올려야 문제를 풀 수 있는 경우가 많다.



