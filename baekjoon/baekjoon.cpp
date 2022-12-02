//problem No. 1238, 파티
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
const int MAX = 1001, INF = 2e9;

vector<pii> g[MAX];
int dist[MAX], visited[MAX];
int toX[MAX], toHome[MAX]; //X, X에서 집으로 가는데 걸리는 시간
int N, M, X, ans;

//from에서 to로 가는 최단거리를 구한 경우, 바로 종료
//to가 0이면 모든 최단거리 구함
void dijkstra(int from, int to) {
	fill(visited, visited + MAX, 0);
	fill(dist, dist + MAX, INF);
	dist[from] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ dist[from], from });
	while (!pq.empty()) {
		int curV = pq.top().second;
		pq.pop();

		if (visited[curV]) continue;
		visited[curV] = 1;

		for (auto& e : g[curV]) {
			int u = e.first, uCost = e.second;

			if (dist[u] > dist[curV] + uCost) {
				dist[u] = dist[curV] + uCost;
				pq.push({ dist[u], u });
			}
		}

		if (curV == to)
			return;
	}
}

int main() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int v, u, d;
		cin >> v >> u >> d;
		g[v].push_back({ u, d });
	}

	//X에서 각 집으로 가는 최단경로 구하기
	dijkstra(X, 0);
	for (int i = 1; i <= N; i++)
		toHome[i] = dist[i];

	//각 집에서 X로 가는 최단경로 구하기
	for (int v = 1; v <= N; v++) {
		dijkstra(v, X);
		toX[v] = dist[X];
	}

	ans = toX[1] + toHome[1];
	for (int v = 2; v <= N; v++)
		ans = max(ans, toX[v] + toHome[v]);
	cout << ans;
}