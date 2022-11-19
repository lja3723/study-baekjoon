//problem No. 1339, 단어 수학
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N, i, j, u;
string dat[10];
vector<int> w(26, 0);

int main() {
	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> dat[i];
		for (j = 1, u = 1; j <= dat[i].size(); j++) {
			w[dat[i][dat[i].size() - j] - 'A'] += u;
			u *= 10;
		};
	}

	sort(w.begin(), w.end(), greater<>());

	int ans = 0;
	for (i = 0; i < 10; i++)
		ans += w[i] * (9 - i);
	
	cout << ans;
}
