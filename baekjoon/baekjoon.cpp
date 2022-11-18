//problem No. 12865, 평범한 배낭
#include <iostream>
#include <vector>
using namespace std;

int R, C, ans = 1;
string map[20];
int visited[20][20];
int showed[26];

void dfs(int i, int j, int len) {
	if (visited[i][j]) return;
	visited[i][j] = 1;
	showed[map[i][j] - 'A'] = 1;

	int di[] = { 1, -1, 0, 0 };
	int dj[] = { 0, 0, 1, -1 };

	int visit = 0;
	for (int d = 0; d < 4; d++) {
		int ni = i + di[d];
		int nj = j + dj[d];

		if (!(0 <= ni && ni < R) || !(0 <= nj && nj < C))
			continue;
		if (visited[ni][nj])
			continue;
		if (showed[map[ni][nj] - 'A']) {
			//visited[ni][nj] = 1;
			continue;
		}

		showed[map[ni][nj] - 'A'] = 1;
		dfs(ni, nj, len + 1);
		showed[map[ni][nj] - 'A'] = 0;	
		visit++;
	}

	visited[i][j] = 0;
	if (!visit) {
		ans = max(ans, len);
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> map[i];

	dfs(0, 0, 1);

	cout << ans;
}
