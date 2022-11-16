//problem No. 2583, 영역 구하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K, i, j, cnt;
int map[100][100];
vector<int> area;

void dfs(int i, int j) {
	if (map[i][j]) return;
	cnt++;
	map[i][j] = 1;

	int di[] = { 1, -1, 0, 0 };
	int dj[] = { 0, 0, 1, -1 };
	for (int d = 0; d < 4; d++) {
		int ni = i + di[d];
		int nj = j + dj[d];

		if (!(0 <= ni && ni < M) || !(0 <= nj && nj < N)) 
			continue;
		if (map[ni][nj])
			continue;

		dfs(ni, nj);
	}
}

int main() {
	cin >> M >> N >> K;

	while (K--) {
		int bj, bi, ej, ei;
		cin >> bj >> bi >> ej >> ei;
		for (i = bi; i < ei; i++)
			for (j = bj; j < ej; j++)
				map[i][j] = 1;
	}

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			if (!map[i][j]) {
				cnt = 0;
				dfs(i, j);
				area.push_back(cnt);
			}

	sort(area.begin(), area.end());

	cout << area.size() << "\n";
	for (int a : area)
		cout << a << " ";
}
