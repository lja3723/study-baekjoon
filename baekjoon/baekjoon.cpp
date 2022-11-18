//problem No. 1439, 뒤집기
#include <iostream>
#include <vector>
using namespace std;

string S;
int cnt[2];

int main() {
	cin >> S;
	char cur = S[0];

	for (int i = 1; i < S.size(); i++) {
		if (cur != S[i]) {
			cnt[cur - '0']++;
			cur = S[i];
		}
	}
	cnt[cur - '0']++;

	cout << min(cnt[0], cnt[1]);
}
