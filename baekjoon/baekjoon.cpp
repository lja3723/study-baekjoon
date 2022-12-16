﻿//problem No. 2644, 촌수계산
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, n1, n2, x, y, m, i, d[101];
vector<int> g[101];

int main() {
	cin >> n >> n1 >> n2 >> m;
	while (m--) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	fill(d, d + 101, -1);
	queue<int> q;
	q.push(n1);
	d[n1] = 0;

	while (!q.empty()) {
		x = q.front(); q.pop();

		for (int y : g[x]) {
			if (d[y] == -1) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}

	cout << d[n2];
}