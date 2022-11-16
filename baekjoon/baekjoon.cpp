//problem No. 7576, 토마토
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct IJT { int i, j, t; }; //좌표(i,j) 시간t

int map[1000][1000], i, j, N, M;
queue<IJT> q;

int main() {
	cin >> M >> N;

	int tCnt = 0; //처음 안익은 토마토 수
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				q.push({ i, j, 0 });
			else if (map[i][j] == 0)
				tCnt++;
		}

	int ans = 0;
	int rtCnt = 0; //시간이 지나 익은 토마토 수
	while (!q.empty()) {
		IJT cur = q.front(); q.pop();
		ans = cur.t;

		int di[] = { 0, 0, -1, 1 };
		int dj[] = { -1, 1, 0, 0 };
		for (i = 0; i < 4; i++) {
			int ni = cur.i + di[i];
			int nj = cur.j + dj[i];
			if (!(0 <= ni && ni < N) || !(0 <= nj && nj < M))
				continue;
			if (map[ni][nj] == -1 || map[ni][nj] == 1)
				continue;

			map[ni][nj] = 1;
			rtCnt++;
			q.push({ ni, nj, cur.t + 1 });
		}
	}

	cout << (tCnt == rtCnt ? ans : -1);
}
