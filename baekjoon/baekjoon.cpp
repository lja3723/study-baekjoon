//problem No. 7562, 나이트의 이동
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct IJ { int i, j, mv; };

int map[300][300];
int I, T, i, j;

void bfs() {
	queue<IJ> q;
	cin >> i >> j;
	q.push({ i, j, 0 });
	map[i][j] = 1;

	cin >> i >> j;
	IJ goal{ i, j, 0 };

	int ans = 0;
	while (!q.empty()) {
		IJ cur = q.front(); q.pop();

		if (cur.i == goal.i && cur.j == goal.j) {
			cout << cur.mv << "\n";
			return;
		}

		int di[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
		int dj[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
		for (int d = 0; d < 8; d++) {
			int ni = cur.i + di[d];
			int nj = cur.j + dj[d];

			if (!(0 <= ni && ni < I) || !(0 <= nj && nj < I))
				continue;
			if (map[ni][nj])
				continue;

			q.push({ ni, nj, cur.mv + 1 });
			map[ni][nj] = 1;
		}
	}
}

int main() {
	cin >> T;
	while (T--) {
		cin >> I;
		for (i = 0; i < I; i++)
			fill(map[i], map[i] + I, 0);
		bfs();
	}
}
