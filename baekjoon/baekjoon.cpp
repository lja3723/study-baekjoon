//problem No. 9375, 패션왕 신해빈
#include <iostream>
#include <map>
using namespace std;

int T, n;

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		map<string, int> m;
		for (int i = 0; i < n; i++) {
			string tmp; cin >> tmp >> tmp;
			if (m.find(tmp) != m.end())
				m[tmp]++;
			else
				m[tmp] = 1;
		}

		long long ret = 1;

		for (auto it = m.begin(); it != m.end(); it++)
			ret *= it->second + 1;
		cout << ret - 1 << "\n";
	}

}