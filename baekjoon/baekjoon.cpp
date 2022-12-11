//problem No. 1389, 케빈 베이컨의 6단계 법칙
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, i, j;
int dist[102][101];
vector<int> g[101];

void bfs(int v) {
	fill(dist[v], dist[v] + 101, -1);

	queue<int> q;
	dist[v][v] = 0;
	q.push(v);

	while (!q.empty()) {
		int cv = q.front(); q.pop();
		for (int u : g[cv]) {
			if (dist[v][u] == -1) {
				dist[v][u] = dist[v][cv] + 1;
				q.push(u);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (i = 0; i < M; i++) {
		int v, u;
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	for (i = 1; i <= N; i++)
		bfs(i);

	int minval = 2e9, idx;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++)
			dist[101][i] += dist[i][j];
		if (minval > dist[101][i]) {
			minval = dist[101][i];
			idx = i;
		}
	}

	cout << idx;
}