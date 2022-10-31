//problem No. 9465, 스티커
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int t, n;
int score[2][MAX];
int dp[2][MAX];

int main()
{
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> score[i][j];
		
		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = score[0][1];
		dp[1][1] = score[1][1];
		
		for (int i = 2; i <= n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + score[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + score[1][i];
		}

		cout << max(dp[0][n], dp[1][n]) << "\n";
	}
}