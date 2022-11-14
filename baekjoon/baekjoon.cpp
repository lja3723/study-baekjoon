//problem No. 1260, DFS와 BFS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
vector<vector<int>> graph(1001);
vector<int> visited(1001);

void dfs(int V) {
	cout << V << " ";
	
	for (int v : graph[V])
		if (!visited[v]) {
			visited[v]++;
			dfs(v);
		}
}

void bfs(int V) {
	queue<int> q;	
	q.push(V);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		cout << v << " ";

		for (int nv : graph[v])
			if (!visited[nv]) {
				visited[nv]++;
				q.push(nv);
			}
	}
}

int main()
{
	cin >> N >> M >> V;
	
	for (int i = 0; i < M; i++) {
		int v, u;
		cin >> v >> u;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}

	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	visited[V]++;
	dfs(V);
	cout << "\n";

	fill(visited.begin(), visited.end(), 0);
	visited[V]++;
	bfs(V);
}
