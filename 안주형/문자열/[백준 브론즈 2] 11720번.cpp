#include <iostream>
using namespace std;

int main() {

    int cnt;
    char N;
    int sum = 0;
    cin >> cnt;

    while (cnt-- > 0) {
        cin >> N;
        sum += (N - '0');
    }
    cout << sum;
}
