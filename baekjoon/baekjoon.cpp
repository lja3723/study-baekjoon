﻿//problem No. 1967, 트리의 지름
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 10001

int V;
vector<pair<int, int>> g[MAX];
int vt[MAX]; //거리저장

void bfs(int v) {
	for (int i = 0; i < MAX; i++)
		vt[i] = -1;

	queue<int> q;
	vt[v] = 0;
	q.push(v);

	while (!q.empty()) {
		int cv = q.front();
		q.pop();

		for (auto& e : g[cv]) {
			int u = e.first;
			int d = e.second;

			if (vt[u] == -1) {
				vt[u] = vt[cv] + d;
				q.push(u);
			}
		}
	}
}

int main() {
	cin >> V;

	for (int i = 0; i < V - 1; i++) {
		int v, u, d;
		cin >> v >> u >> d;
		g[v].push_back({ u, d });
		g[u].push_back({ v, d });
	}

	bfs(1);
	bfs(max_element(begin(vt), end(vt)) - begin(vt));
	cout << *max_element(begin(vt), end(vt));
}