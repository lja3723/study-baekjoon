//problem 11055, 가장 큰 증가 부분 수열
#include <iostream>
using namespace std;

int dat[1001], N, i, j, dp[1001];

int main() {
	cin >> N;
	
	for (i = 1; i <= N; i++) 
		cin >> dat[i];

	int ans = 0;
	for (i = 1; i <= N; i++) {
		dp[i] = dat[i];
		for (j = 1; j < i; j++)
			if (dat[j] < dat[i])
				dp[i] = max(dp[i], dp[j] + dat[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans;
}
