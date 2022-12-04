﻿//problem No. 1167, 트리의 지름
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 100001

int V;
vector<pair<int, int>> g[MAX];
int vt[MAX];

//vt에 v로부터 떨어진 거리가 저장됨
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

	for (int i = 0; i < V; i++) {
		int v, u, d;
		cin >> v >> u;
		while (u != -1) {
			cin >> d;
			g[v].push_back({ u, d });
			cin >> u;
		}
	}

	//임의의 한 정점에서 가장 먼 정점을 찾고, 그 정점에서 가장 먼 정점을 출력
	bfs(1);
	bfs(max_element(begin(vt), end(vt)) - begin(vt));
	cout << *max_element(begin(vt), end(vt));
}