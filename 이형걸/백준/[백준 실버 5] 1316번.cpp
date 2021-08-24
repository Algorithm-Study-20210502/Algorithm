// 문자열 문제

// string.find(str[i]) 의 방식으로 풀어도 되고,
// Alphabet[26] 배열을 선언후, 각각의 알파벳 갯수를 세는 방식으로 문제를 풀어도 된다.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, Answer;
string Str;
vector<int> Alphabet;

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		bool flag = true;

		cin >> Str;

		Alphabet.assign(26, 0);

		for (int i = 0; i < Str.length(); ++i) {
			if (Alphabet[Str[i] - 'a'] == 0) {
				++Alphabet[Str[i] - 'a'];
			}
			else {
				if (Str[i] == Str[i - 1]) {
					continue;
				}
				else {
					flag = false;
					break;
				}
			}
		}

		if (flag) {
			++Answer;
		}
	}

	cout << Answer << '\n';

	return 0;
}

//------------- 예전 풀이 -----------------------//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, Count;
vector<int> Alphabet(101, 0);
string str;

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> str;
		//Alphabet.assign(101, 0);
		Alphabet.assign(26, 0);

		if (str.length() == 1) {
			++Count;
			continue;
		}

		//int index = str.find(str[0]);
		int index = str[0] - 'a';
		++Alphabet[index];

		for (int j = 1; j < str.length(); ++j) {
			//int index = str.find(str[j]);
			int index = str[j] - 'a';
			if (Alphabet[index] != 0 && str[j - 1] != str[j]) {
				break;
			}
			else {
				++Alphabet[index];
			}

			if (j == str.length() - 1) {
				++Count;
			}
		}
	}

	cout << Count << '\n';

	return 0;
}