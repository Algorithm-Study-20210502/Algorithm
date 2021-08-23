#include <iostream>
using namespace std;

int main() {

	int cnt;
	char N;
	int sum = 0;
	cin >> cnt;

	while (cnt--) {
		cin >> N;
		sum += (N - '0');
	}
	cout << sum;
}
