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

## 활용 1 : **파라메트릭 서치(Parametric Search)** 

**최적화 문제를 결정 문제('예' 혹은 '아니오') 로 바꾸어 해결하는 기법이다.**

최적화 문제 : 어떤 함수의 값을 가능한 낮추거나 어떤 함수의 값을 최대한 높이는 문제

결정 문제 : '예' 혹은 '아니오' 로 답하는 문제를 말한다.

- 예시 : 특정한 조건을 만족하는 가장 알맞은 값을 빠르게 찾는 최적화 문제
  
  - 범위 내에서 조건을 만족하는 가장 큰 값을 찾으라는 최적화 문제 -> 이진 탐색으로 결정 문제를 해결하면서 범위를 좁혀갈 수 있다.
   
- 일반적으로 코딩 테스트에서 파라메트릭 서치 문제는 **이진 탐색** 을 이용하여 해결할 수 있다. 

예제) [(백준 실버 3) 2805번 나무 자르기 문제 링크](https://www.acmicpc.net/problem/2805)

-  [(백준 실버 3) 2805번 나무 자르기 풀이 링크](https://github.com/LeeHyungGeol/Algorithm_BaekJoon/blob/master/%EB%B0%B1%EC%A4%80_if%EB%AC%B8/%5B%EB%B0%B1%EC%A4%80%20%EC%8B%A4%EB%B2%84%203%5D%202805%EB%B2%88.cpp)

```c++
// 전형적인 이분 탐색을 이용한 파라메트릭 서치 문제
// (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)
// 범위의 단위가 10억이나 되기 때문에, 이분 탐색을 생각할 수 있어야 한다.

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1e9

using namespace std;

typedef long long int ll;

int N, M;
vector<int> tree;

int main() {	
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int height;
		cin >> height;
		tree.push_back(height);
	}

	int start = 0;
	int end = MAX;
	ll result = 0;

	while (start <= end) {
		ll sum = 0;

		int mid = (start + end) / 2;

		for (int i = 0; i < N; ++i) {
			if (tree[i] > mid) {
				sum += tree[i] - mid;
			}
		}
		
		// 자르는 높이를 높게 설정하여 가져갈 수 있는 나무가 M보다 작으므로
		// end를 더 작게 설정한다. (왼쪽 부분 탐색)
		if (sum < M) {
			end = mid - 1;
		}
		// 나무의 양이 M이상인 경우 덜 자르기 (오른쪽 부분 탐색)
		else {
			// 설정할 수 있는 높이의 최댓값이라고 했으므로, 여기에 result를 기록한다.
			result = mid;
			start = mid + 1;
		}
	}

	cout << result << '\n';

	return 0;
}
```
- 적절한 높이를 찾을 때까지 이진 탐색을 수행하여 높이 H를 반복해서 조정하면 된다.

- '현재 이 높이로 자르면 조건을 만족할 수 있는가?' 를 확인한 뒤에 **조건의 만족 여부('예' 혹은 '아니오') 에 따라서 탐색 범위를 좁혀서 해결** 할 수 있다.

- 절단기의 높이는 `0 ~ 10억` 까지의 정수 중 하나이다.
  
  - 이렇게 큰 탐색 범위를 보면 가장 먼저 **이진 탐색** 을 떠올려야 한다.  

- 현재의 높이에서 잘랐을 때 필요한 나무의 크기(M) 이상의 나무를 얻을 수 있다면, **그때마다 결과를 기록해서** 최종적으로 더이상 이진 탐색을 수행할 수 없을 때까지 반복 했을 때 기록되어 있는 결과값을 출력한다. 

## 활용 2 : C++ 이진 탐색 라이브러리 : lower_bound(), upper_bound()

### lower_bound

- 용도 : 찾으려는 **key 값보다 같거나 큰 숫자** 가 배열 몇 번째에서 **처음 등장** 하는지 찾기 위함

- 사용 조건 : 탐색을 진행할 배열 혹은 벡터는 **오름차순 정렬** 되어 있어야 한다.

```c++
#include <algorithm>

// 벡터(vector) 
vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);

int leftIndex = lower_bound(v.begin(), v.end(), leftValue) - v.begin();

// 배열(array)
int leftIndex = lower_bound(arr, arr + N, leftValue) - arr;
```

- `lower_bound의 반환형` 은 **Iterator** 이므로 실제로 몇 번째 인덱스인지 알고 싶다면, 위 코드와 같이 lower_bound 값에서 **배열 첫 번째 주소** 를 가리키는 **배열의 이름** 을 빼 주면 됩니다.

- **벡터** 의 경우, **v.begin()** 을 빼 주면 됩니다.

### upper_bound()

- 용도 : 찾으려는 key 값을 **초과하는 숫자** 가 배열 몇 번째에서 **처음 등장**하는지 찾기 위함

- 사용 조건 : 탐색을 진행할 배열 혹은 벡터는 **오름차순 정렬** 되어 있어야 함

```c++
#include <algorithm>

// 벡터(vector)
vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);

int rightIndex = upper_bound(v.begin(), v.end(), rightValue) - v.begin();

// 배열(array)
int rightIndex = upper_bound(arr, arr + N, rightValue) - arr;
```

### EX) 정렬된 배열에서 특정 수의 개수 구하기

1. **라이브러리를 사용 : countByRange**

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, x;
vector<int> arr;

int countByRange(vector<int>& arr, int leftValue, int rightValue);

int main() {
    // 데이터의 개수 N, 찾고자 하는 값 x 입력 받기
    cin >> N >> x;

    // 전체 데이터 입력 받기
    for(int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    // 값이 [x, x] 범위에 있는 데이터의 개수 계산
    int count = countByRange(arr, x, x);

    // 값이 x인 원소가 존재하지 않는다면
    if(count == 0) {
        cout << "-1" << '\n';
    }
    // 값이 x인 원소가 존재한다면
    else {
        cout << cnt << '\n';
    }
    return 0;
}

int countByRange(vector<int>& arr, int leftValue, int rightValue) {
    int rightIndex = upper_bound(arr.begin(), arr.end(), rightValue) - arr.begin();
    int leftIndex = lower_bound(arr.begin(), arr.end(), leftValue) - arr.begin();

    return rightIndex - leftIndex;
}
```

2. **라이브러리를 사용하지 않고 구현 : countByValue**

```c++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, x;
vector<int> arr;

int countByValue(vector<int>& arr, int target);
int first(vector<int>& arr, int target, int start, int end);
int last(vector<int>& arr, int target, int start, int end);

int main() {
    cin >> N >> x;
    
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    int count = countByValue(arr, x);

    // 값이 x인 원소가 존재하지 않는다면
    if(count == 0) {
        cout << "-1" << '\n';
    }
    // 값이 x인 원소가 존재한다면
    else {
        cout << cnt << '\n';
    }
    return 0;
}

int countByValue(vector<int>& arr, int target) {
    // target 이 처음 등장한 index를 return
    int leftIndex = first(arr, target, 0, N - 1);

    // 배열에 원소가 존재하지 않는 경우 0을 return
    if(leftIndex == -1) {
        return 0;
    }

    // target 이 마지막으로 등장한 index를 return
    int rightIndex = last(arr, target, 0, N - 1);

    return rightIndex - leftIndex + 1;
}

int first(vector<int>& arr, int target, int start, int end) {
    if(start > end) {
        return -1;
    }

    int mid = (start + end) / 2;
    
    // target값을 가지는 원소 중에서 가장 왼쪽에 있는 경우에만 인덱스 값을 리턴
    if (arr[mid] == target && (mid == 0 || target > arr[mid - 1])) {
        return mid;
    }
    // 중간 점의 값보다 target값이 작거나 같은 경우에 (왼쪽을 탐색)
    else if(arr[mid] >= target) {
        return first(arr, target, start, mid -1);
    }
    // 중간 점의 값보다 target값이 큰 경우에 (오른쪽을 탐색)
    else {
        return first(arr, target, mid + 1, end);
    }
}

int last(vector<int>& arr, int target, int start, int end) {
    if(start > end) {
        return -1;
    }

    int mid = (start + end) / 2;

    // target 값을 가진 원소 중에서 가장 오른 쪽에 있는 경우에만 인덱스 반환
    if(arr[mid] == target && (mid == N - 1 && arr[mid + 1] > target)) {
        return mid;
    }
    // 중간 점의 값 보다 target 값이 작은 경우 (왼쪽을 탐색)
    else if(arr[mid] > target) {
        return last(arr, target, start, mid - 1);
    }
    // 중간 점의 값 보다 target 값이 크거나 같은 경우 (오른쪽을 탐색)
    else {
        return last(arr, target, mid + 1, end);
    }
}
```

## 이분 탐색 관련 문제들

- [(백준 실버 4) 1920번 수 찾기 문제 링크](https://www.acmicpc.net/problem/1920)
  - [(백준 실버 4) 1920번 수 찾기 풀이 링크](https://github.com/LeeHyungGeol/Algorithm_BaekJoon/blob/master/%EB%B0%B1%EC%A4%80_if%EB%AC%B8/%EC%9D%B4%EB%B6%84%20%ED%83%90%EC%83%89_%EC%88%98%20%EC%B0%BE%EA%B8%B0_countByValue(%EC%A0%95%EB%A0%AC%20%ED%95%84%EC%9A%94).cpp)

- [(백준 실버 4) 10816번 숫자 카드 2 문제 링크](https://www.acmicpc.net/problem/10816)
  - [(백준 실버 4) 10816번 숫자 카드 2 풀이 링크 : 라이브러리 미사용](https://github.com/LeeHyungGeol/Algorithm_BaekJoon/blob/master/%EB%B0%B1%EC%A4%80_if%EB%AC%B8/%EC%9D%B4%EB%B6%84%20%ED%83%90%EC%83%89_%EC%88%AB%EC%9E%90%20%EC%B9%B4%EB%93%9C%202_countByValue(%EC%A0%95%EB%A0%AC%20%ED%95%84%EC%9A%94).cpp) 
  - [(백준 실버 4) 10816번 숫자 카드 2 풀이 링크 : 라이브러리 사용](https://github.com/LeeHyungGeol/Algorithm_BaekJoon/blob/master/%EB%B0%B1%EC%A4%80_if%EB%AC%B8/%EC%9D%B4%EB%B6%84%20%ED%83%90%EC%83%89_%EC%88%AB%EC%9E%90%20%EC%B9%B4%EB%93%9C%202_countByRange(%EC%A0%95%EB%A0%AC%20%ED%95%84%EC%9A%94).cpp)

- [(백준 실버 3) 1654번 랜선 자르기 문제 링크](https://www.acmicpc.net/problem/1654)
  - [(백준 실버 3) 1654번 랜선 자르기 풀이 링크](https://github.com/LeeHyungGeol/Algorithm_BaekJoon/blob/master/%EB%B0%B1%EC%A4%80_if%EB%AC%B8/%EC%9D%B4%EB%B6%84%20%ED%83%90%EC%83%89_%EB%9E%9C%EC%84%A0%20%EC%9E%90%EB%A5%B4%EA%B8%B0.cpp)

- [(백준 실버 3) 2805번 나무 자르기 문제 링크](https://www.acmicpc.net/problem/2805)
  - [(백준 실버 3) 2805번 나무 자르기 풀이 링크](https://github.com/LeeHyungGeol/Algorithm_BaekJoon/blob/master/%EB%B0%B1%EC%A4%80_if%EB%AC%B8/%EC%9D%B4%EB%B6%84%20%ED%83%90%EC%83%89_%EB%82%98%EB%AC%B4%20%EC%9E%90%EB%A5%B4%EA%B8%B0_%EC%9D%B4%EB%B6%84%20%ED%83%90%EC%83%89%EC%9D%84%20%EC%9D%91%EC%9A%A9%ED%95%98%EC%97%AC%20%EC%B5%9C%EC%86%9F%EA%B0%92%EC%9D%B4%EB%82%98%20%EC%B5%9C%EB%8C%93%EA%B0%92%EC%9D%84%20%EC%B0%BE%EB%8A%94%20%EB%AC%B8%EC%A0%9C%202.cpp)   

- [(백준 실버 1) 2110번 공유기 설치 문제 링크](https://www.acmicpc.net/problem/2110)
  - [(백준 실버 1) 2110번 공유기 설치 풀이 링크](https://github.com/LeeHyungGeol/Algorithm_BaekJoon/blob/master/%EB%B0%B1%EC%A4%80_if%EB%AC%B8/%EC%9D%B4%EB%B6%84%20%ED%83%90%EC%83%89_%EA%B3%B5%EC%9C%A0%EA%B8%B0%20%EC%84%A4%EC%B9%98_%EC%9D%B4%EB%B6%84%20%ED%83%90%EC%83%89%EC%9D%84%20%EC%9D%91%EC%9A%A9%ED%95%98%EC%97%AC%20%EC%B5%9C%EC%86%9F%EA%B0%92%EC%9D%B4%EB%82%98%20%EC%B5%9C%EB%8C%93%EA%B0%92%EC%9D%84%20%EC%B0%BE%EB%8A%94%20%EB%AC%B8%EC%A0%9C%203.cpp)

- [(백준 골드 3) 1300번 K번째 수 문제 링크](https://www.acmicpc.net/problem/1300) 
  - [(백준 골드 3) 1300번 K번째 수 풀이 링크](https://github.com/LeeHyungGeol/Algorithm_BaekJoon/blob/master/%EB%B0%B1%EC%A4%80_if%EB%AC%B8/%EC%9D%B4%EB%B6%84%20%ED%83%90%EC%83%89_K%EB%B2%88%EC%A7%B8%20%EC%88%98.cpp)  

- [(백준 골드 2) 12015번 가장 긴 증가하는 부분 수열 2 문제 링크](https://www.acmicpc.net/problem/12015)  
  - [(백준 골드 2) 12015번 가장 긴 증가하는 부분 수열 2 풀이 링크](https://github.com/LeeHyungGeol/Algorithm_BaekJoon/blob/master/%EB%B0%B1%EC%A4%80_if%EB%AC%B8/%EC%9D%B4%EB%B6%84%20%ED%83%90%EC%83%89_%20%EA%B0%80%EC%9E%A5%20%EA%B8%B4%20%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94%20%EB%B6%80%EB%B6%84%20%EC%88%98%EC%97%B4%202.cpp) 









