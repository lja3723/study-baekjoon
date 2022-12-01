//problem No. 1753, 최단경로
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int MAX = 20000, INF = 1e9;

/*
데이터 형식:
N(정점수) M(간선수) S(시작정점)
시작정점 끝정점 가중치
...(M개)...

case 1:
6 9 1
1 3 9
1 2 7
2 3 10
2 4 15
3 4 11
4 5 6
5 6 9
6 1 14
7 3 2
ANS: 0 7 9 20 20 11

case 2:
5 8 1
1 2 5
1 3 3
1 4 7
2 3 4
3 4 3
2 5 7
3 5 8
4 5 4
ANS: 0 5 3 6 10
*/

vector<pii> g[MAX];
int dist[MAX], visited[MAX];
int V, E, K;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E >> K;
	K--;
	for (int i = 0; i < E; i++) {
		int v, u, d;
		cin >> v >> u >> d;
		g[v - 1].push_back({ u - 1, d });
	}

	fill(dist, dist + MAX, INF);
	dist[K] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ dist[K], K}); //거리, 정점
	
	while (!pq.empty()) {
		int c = pq.top().first;
		int v = pq.top().second;
		pq.pop();

		for (int i = 0; i < g[v].size(); i++) {
			int u = g[v][i].first;
			int nc = c + g[v][i].second;
			if (nc < dist[u]) {
				dist[u] = nc;
				pq.push({ nc, u });
			}
		}
	}

	for (int i = 0; i < V; i++) {
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}