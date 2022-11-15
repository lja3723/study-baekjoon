//problem No. 9095, 1, 2, 3 더하기
#include <iostream>
#include <vector>
using namespace std;

int dp[11] = { 1 };
int T, n;

int main()
{
	for (int i = 1; i < 11; i++) for (int j = 1; j < 4; j++)
		if (i - j >= 0)
			dp[i] += dp[i - j];

	cin >> T;
	while (T--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
}