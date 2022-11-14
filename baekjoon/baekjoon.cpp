//problem No. 2606, 바이러스
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, ans;
vector<vector<int>> graph(101);
vector<int> visited(101);

void bfs() {
	queue<int> q;	
	q.push(1);
	visited[1]++;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		ans++;

		for (int nv : graph[v])
			if (!visited[nv]) {
				visited[nv]++;
				q.push(nv);
			}
	}
}

int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int v, u;
		cin >> v >> u;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}

	bfs();

	cout << --ans;
}
