//problem No. 2293, 동전 1
#include <iostream>
#include <vector>
using namespace std;

int n, k, i, j;
int dat[101];
int dp[10001] = { 1 };

int main()
{
	cin >> n >> k;
	for (i = 1; i <= n; i++) {
		cin >> dat[i];
	}

	for (i = 1; i <= n; i++) {
		for (j = dat[i]; j <= k; j++) {
			if (j - dat[i] >= 0)
				dp[j] += dp[j - dat[i]];
		}
	}

	cout << dp[k];
}