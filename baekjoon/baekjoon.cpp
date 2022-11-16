//problem No. 4963, 섬의 개수
#include <iostream>
using namespace std;

int map[50][50];
int h, w, i, j, cnt;

void dfs(int i, int j) {
	if (map[i][j] == 0) return;
	map[i][j] = 0;

	int di[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	int dj[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
	for (int d = 0; d < 8; d++) {
		int ni = i + di[d];
		int nj = j + dj[d];
		if (!(0 <= ni && ni < h) || !(0 <= nj && nj < w))
			continue;
		if (map[ni][nj] == 0)
			continue;

		dfs(ni, nj);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++)
				cin >> map[i][j];

		cnt = 0;
		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					cnt++;
					dfs(i, j);
				}
			}

		cout << cnt << "\n";
	}
}
