//problem No. 1753, 최단경로
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
const int MAX = 20001, INF = 2e9;

int V, E, K, i;
vector<pii> g[MAX];
int visited[MAX], dist[MAX];

void dijkstra(int from, int to) {
	fill(visited + 1, visited + V + 1, 0);
	fill(dist + 1, dist + V + 1, INF);
	dist[from] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ dist[from], from });
	while (!pq.empty()) {
		int curV = pq.top().second;
		pq.pop();

		if (visited[curV]) continue;
		visited[curV] = 1;

		for (i = 0; i < g[curV].size(); i++) {
			int u = g[curV][i].first;
			int uCost = g[curV][i].second;
			if (dist[u] > dist[curV] + uCost) {
				dist[u] = dist[curV] + uCost;
				pq.push({ dist[u], u });
			}
		}

		if (curV == to) break;
	}
}

int main() {
	cin >> V >> E >> K;
	for (i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({ v, w });
	}

	dijkstra(K, 0);

	for (i = 1; i <= V; i++)
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
}