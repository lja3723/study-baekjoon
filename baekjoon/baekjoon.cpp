//problem No. 2156, 포도주 시식
#include <iostream>
#include <algorithm>
using namespace std;

int n, i;
int dat[10001];
int dp[10001];

int main() {
	cin >> n;
	for (i = 1; i <= n; i++) cin >> dat[i];

	dp[1] = dat[1];
	dp[2] = dat[1] + dat[2];

	for (i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + dat[i - 1]) + dat[i];
		dp[i] = max(dp[i - 1], dp[i]);
	}

	cout << dp[n];
}
