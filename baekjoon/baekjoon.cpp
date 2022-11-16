//problem No. 7569, 토마토
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct HIJT { int h, i, j, t; }; //좌표(h,i,j) 시간t

int map[100][100][100], h, i, j, N, M, H;
queue<HIJT> q;

int main() {
	cin >> M >> N >> H;

	int tCnt = 0; //처음 안익은 토마토 수
	for (h = 0; h < H; h++)
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++) {
				cin >> map[h][i][j];
				if (map[h][i][j] == 1)
					q.push({ h, i, j, 0 });
				else if (map[h][i][j] == 0)
					tCnt++;
			}

	int ans = 0;
	int rtCnt = 0; //시간이 지나 익은 토마토 수
	while (!q.empty()) {
		HIJT cur = q.front(); q.pop();
		ans = cur.t;

		int dh[] = { -1, 1, 0, 0, 0, 0 };
		int di[] = { 0, 0, 0, 0, -1, 1 };
		int dj[] = { 0, 0, -1, 1, 0, 0 };
		for (i = 0; i < 6; i++) {
			int nh = cur.h + dh[i];
			int ni = cur.i + di[i];
			int nj = cur.j + dj[i];
			if (!(0 <= nh && nh < H) || !(0 <= ni && ni < N) || !(0 <= nj && nj < M))
				continue;
			if (map[nh][ni][nj] == -1 || map[nh][ni][nj] == 1)
				continue;

			map[nh][ni][nj] = 1;
			rtCnt++;
			q.push({ nh, ni, nj, cur.t + 1 });
		}
	}

	cout << (tCnt == rtCnt ? ans : -1);
}
