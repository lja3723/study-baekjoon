//problem No. 20529, 가장 가까운 세 사람의 심리적 거리
#include <iostream>
#include <vector>
using namespace std;

int T, N;

int f(string& s1, string& s2) {
	int ret = 0;
	for (int i = 0; i < 4; i++)
		if (s1[i] != s2[i]) ret++;
	return ret;
}

int sel[3];
int ans;

void bt(vector<string>& v, int start, int depth) {
	if (depth >= 3) {
		ans = min(ans, f(v[sel[0]], v[sel[1]]) + f(v[sel[0]], v[sel[2]]) + f(v[sel[1]], v[sel[2]]));
		return;
	}

	for (int i = start; i < N - (2 - depth); i++) {
		sel[depth] = i;
		bt(v, i + 1, depth + 1);
	}
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		vector<string> v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		if (N > 32) {
			cout << "0\n";
			continue;
		}
		ans = 2e9;
		bt(v, 0, 0);
		cout << ans << "\n";
	}
}