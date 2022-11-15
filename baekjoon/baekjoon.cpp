//problem No. 1912, 연속합
#include <iostream>
using namespace std;

int dp[100001];

int main() {
	int n;
	cin >> n;

	//dp[0] = -1000;

	int ans = -1e9;
	for (int dn = 1; dn <= n; dn++) {
		cin >> dp[dn];
		dp[dn] = max(dp[dn - 1] + dp[dn], dp[dn]);
		ans = max(ans, dp[dn]);
	}

	cout << ans;
}
