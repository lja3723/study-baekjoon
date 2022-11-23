//problem 1520, 내리막 길
#include <iostream>
using namespace std;

int M, N, i, j;
int map[501][501], dp[501][501];

int getPathCnt(int m, int n) {
	if (dp[m][n] != -1)
		return dp[m][n];

	dp[m][n] = 0;

	int di[] = { 1, -1, 0, 0 };
	int dj[] = { 0, 0, 1, -1 };
	for (int d = 0; d < 4; d++) {
		int ni = m + di[d];
		int nj = n + dj[d];

		if (!(0 < ni && ni <= M) || !(0 < nj && nj <= N))
			continue;
		if (map[ni][nj] <= map[m][n])
			continue;

		dp[m][n] += getPathCnt(ni, nj);
	}

	return dp[m][n];
}

int main() {
	cin >> M >> N;
	for (i = 1; i <= M; i++)
		for (j = 1; j <= N; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}

	dp[1][1] = 1;
	cout << getPathCnt(M, N);

}
