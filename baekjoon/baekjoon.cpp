//problem No. 1932, 정수 삼각형
#include <iostream>
using namespace std;

int dp[500][501];


int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 1; j <= i + 1; j++) {
			cin >> dp[i][j];
			if (i > 0) 
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);			
		}
	
	int ans = 0;
	for (int i = 1; i <= N; i++)
		ans = max(ans, dp[N - 1][i]);

	ios::sync_with_stdio(0), cin.tie(0);

	cout << ans;
}
