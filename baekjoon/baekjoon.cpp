//problem No. 1915, 가장 큰 정사각형
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, i, j, k;
int map[1000][1000], dp[1000][1000];

int main() {
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (j = 0; j < M; j++)
			map[i][j] = s[j] - '0';
	}
	int ans = 0;

	for (i = 0; i < N; i++) {
		dp[i][0] = map[i][0];
		ans = max(ans, dp[i][0]);
	}

	for (j = 1; j < M; j++) {
		dp[0][j] = map[0][j];
		ans = max(ans, dp[0][j]);
	}

	for (i = 1; i < N; i++) {
		for (j = 1; j < M; j++) {
			if (map[i][j] == 0)
				dp[i][j] = 0;
			else 
				dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
			
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans * ans;
}
