//problem No. 1931, 회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SE { int s, e; };

int N, n, i, j;
vector<SE> T;

int main() {
	cin >> N;
	n = N;
	while (n--) {
		cin >> i >> j;
		T.push_back({ i, j });
	}
	sort(begin(T), end(T), [](SE& l, SE& r) {
		if (l.e != r.e)
		return l.e < r.e;
		else
			return l.s < r.s;
	});

	int cnt = 1, last = 0;
	for (i = 1; i < N; i++) {
		if (T[i].s >= T[last].e) {
			cnt++;
			last = i;
		}
	}


	cout << cnt;
}
