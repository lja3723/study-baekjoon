//problem No. 10844, 쉬운 계단수
#include <iostream>
using namespace std;

int dp[101][10];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i < 10; i++)
		dp[1][i]++;

	int p = 1e9;
	for (int n = 2; n <= N; n++) {
		dp[n][0] = dp[n - 1][1] % p;

		for (int j = 1; j <= 8; j++)
			dp[n][j] = (dp[n - 1][j - 1] + dp[n - 1][j + 1]) % p;

		dp[n][9] = dp[n - 1][8] % p;
	}

	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans = (ans + dp[N][i]) % p;

	cout << ans;
}
