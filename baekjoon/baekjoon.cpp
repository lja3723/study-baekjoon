//problem No. 10026, 적록색약
#include <iostream>
using namespace std;

int N, i, j;
string paint[100];
int visited[100][100];

void dfs(int i, int j, char color, int mode) {
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

		if (mode == 0) {
			if (color != paint[ni][nj])
				continue;
		}

		if (mode == 1) {
			if (color == 'B' && paint[ni][nj] != 'B')
				continue;
			if (color != 'B' && paint[ni][nj] == 'B')
				continue;				
		}

		dfs(ni, nj, color, mode);
	}
}

int main() {
	cin >> N;

	for (i = 0; i < N; i++)
		cin >> paint[i];

	int cnt, mode = -1;
	while (++mode < 2) {
		if (mode == 1)
			for (i = 0; i < N; i++)
				fill(visited[i], visited[i] + N, 0);

		cnt = 0;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (!visited[i][j]) {
					cnt++;
					dfs(i, j, paint[i][j], mode);
				}

		cout << cnt << " ";
	}
}
