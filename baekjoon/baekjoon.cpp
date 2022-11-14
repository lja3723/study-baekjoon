//problem No. 2178, 미로 탐색
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct NM { int n, m; };

int N, M, i, j, ans;
int map[102][102];

void bfs() {
	queue<NM> q;
	queue<int> depth;
	q.push({ 1, 1 });
	depth.push(1);
	map[1][1]--;

	while (!q.empty()) {
		NM cur = q.front();
		int cd = depth.front();
		q.pop();
		depth.pop();

		NM d[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
		for (i = 0; i < 4; i++) {
			int cn = cur.n + d[i].n;
			int cm = cur.m + d[i].m;
			if (!map[cn][cm]) continue;

			if (cn == N && cm == M) {
				ans = cd + 1;
				return;
			}

			map[cn][cm]--;
			q.push({ cn, cm });
			depth.push(cd + 1);
		}
	}
}

int main()
{
	cin >> N >> M;
	for (i = 1; i <= N; i++) {
		string line;
		cin >> line;
		for (j = 1; j <= M; j++)
			map[i][j] = int(line[j - 1] - '0');
	}

	bfs();

	cout << ans;
}
