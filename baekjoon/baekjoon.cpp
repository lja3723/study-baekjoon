//problem No. 11057, 오르막 수
#include <iostream>
using namespace std;

int dp[1001][10];

int main()
{
	int N, i, j, k;
	cin >> N;
	for (i = 0; i < 10; i++) dp[1][i]++;

	for (i = 1; i <= N; i++) {
		for (j = 0; j < 10; j++)
			for (k = j; k < 10; k++) {
				dp[i][k] += dp[i - 1][j];
				dp[i][k] %= 10007;
			}
	}

	int ans = 0;
	for (i = 0; i < 10; i++) {
		ans += dp[N][i];
	}
		

	cout << ans % 10007;
}