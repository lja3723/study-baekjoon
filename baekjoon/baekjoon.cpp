//problem No. 10026, 적록색약
#include <iostream>
using namespace std;

int N, i, j, hMax;
int map[100][100];
int visited[100][100];

void dfs(int i, int j) {
	if (visited[i][j]) return;
	visited[i][j] = 1;

	int di[] = { 1, -1, 0, 0 };
	int dj[] = { 0, 0, 1, -1 };
	for (int d = 0; d < 4; d++) {
		int ni = i + di[d];
		int nj = j + dj[d];

		if (!(0 <= ni && ni < N) || !(0 <= nj && nj < N)) 
			continue;
		if (visited[ni][nj])
			continue;

		dfs(ni, nj);
	}
}

int main() {
	cin >> N;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
			hMax = max(hMax, map[i][j]);
		}

	int ans = 0, h, cnt;
	for (h = 0; h <= hMax; h++) {
		for (i = 0; i < N; i++)
			fill(visited[i], visited[i] + N, 0);

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (map[i][j] <= h)
					visited[i][j] = 1;

		cnt = 0;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (!visited[i][j]) {
					cnt++;
					dfs(i, j);
				}

		ans = max(ans, cnt);
	}

	cout << ans;
}
