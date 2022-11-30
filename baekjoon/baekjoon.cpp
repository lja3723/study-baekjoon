//problem No. 1043, 거짓말
#include <iostream>
#include <vector>
using namespace std;

int N, M, i, j, party[50][51], visited[51], know;
vector<int> knows, g[51];

/*
반례:
9 4
1 1
4 1 2 3 4
4 5 6 7 8
2 8 9
2 4 9
*/
void dfs(int v) {
	if (visited[v]) return;
	visited[v] = 1;

	for (int u : g[v]) {
		dfs(u);
	}
}

int main() {
	cin >> N >> M >> know;
	for (i = 0; i < know; i++) {
		cin >> j;
		knows.push_back(j);
	}

	for (i = 0; i < M; i++) {
		cin >> party[i][0]; //파티 참여인원

		for (j = 1; j <= party[i][0]; j++) {
			cin >> party[i][j];
			if (j > 1) { //파티 참여인원끼리의 관계생성
				g[party[i][j - 1]].push_back(party[i][j]);
				g[party[i][j]].push_back(party[i][j - 1]);
			}
		}
	}

	for (int v : knows) dfs(v);

	int ans = 0;
	for (i = 0; i < M; i++) {
		know = 0;
		for (j = 1; !know && j <= party[i][0]; j++)
			if (visited[party[i][j]])
				know = 1;

		if (!know) //진실을 아는 사람이 없는 파티
			ans++;
	}

	cout << ans;
}