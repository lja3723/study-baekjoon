//problem 2206, 벽 부수고 이동하기
#include <iostream>
#include <queue>
using namespace std;

struct IJB { int i, j, b; };

int M, N, i;
string map[1000];
int vt[1000][1000][2];

int bfs() {
	queue<IJB> q;
	q.push({ 0, 0, 0 });
	vt[0][0][0] = 1;

	while (!q.empty()) {
		IJB c = q.front(); q.pop();

		if (c.i == N - 1 && c.j == M - 1)
			return vt[c.i][c.j][c.b];

		int di[] = { 1, -1, 0, 0 };
		int dj[] = { 0, 0, 1, -1 };
		for (int d = 0; d < 4; d++) {
			int ni = c.i + di[d];
			int nj = c.j + dj[d];
			int nb = c.b;
			int goUp = 0;
			
			if (!(0 <= ni && ni < N) || !(0 <= nj && nj < M))
				continue;
			if (vt[ni][nj][nb])
				continue;
			if (map[ni][nj] == '1') {
				if (nb == 1)
					continue;
				else
					nb++, goUp++;
			}

			q.push({ ni, nj, nb });
			vt[ni][nj][nb] = vt[c.i][c.j][nb - goUp] + 1;
		}
	}

	return -1;
}

int main() {
	cin >> N >> M;
	for (i = 0; i < N; i++) cin >> map[i];
	cout << bfs();
}
