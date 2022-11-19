//problem No. 1715, 카드 정렬하기
#include <iostream>
#include <queue>
using namespace std;

int N, i, d;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> d;
		pq.push(d);
	}

	int ans = 0;
	while (pq.size() > 1) {
		int x1, x2;
		x1 = pq.top(); pq.pop();
		x2 = pq.top(); pq.pop();
		ans += x1 + x2;
		pq.push(x1 + x2);
	}

	cout << ans;
}
