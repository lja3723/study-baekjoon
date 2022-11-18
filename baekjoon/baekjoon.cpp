//problem No. 1946, 신입 사원
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T, N, i;

	cin >> T;
	while (T--) {
		cin >> N;

		vector<pair<int, int>> v;
		for (i = 0; i++ < N;) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a, b });
		}
		sort(begin(v), end(v));

		int ans = 1;
		int rank = v[0].second;
		for (i = 1; i < N; i++) {
			if (v[i].second < rank) {
				rank = v[i].second;
				ans++;
			}
		}

		cout << ans << "\n";
	}
}
