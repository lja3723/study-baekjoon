//problem No. 16928, 뱀과 사다리 게임
#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
	vector<int> dist(101, -1);
	map<int, int> m;

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		int x, y;
		cin >> x >> y;
		m[x] = y;
	}

	queue<int> q;
	q.push(1); dist[1] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		
		if (cur == 100) {
			cout << dist[100];
			return 0;
		}

		for (int d = 1; d <= 6; d++) {
			int n = cur + d;
			if (n > 100) continue;

			if (m.find(n) != m.end())
				n = m[n];			

			if (dist[n] > -1) continue;

			q.push(n);
			dist[n] = dist[cur] + 1;
		}
	}
}