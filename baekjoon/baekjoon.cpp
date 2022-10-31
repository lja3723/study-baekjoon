//problem No. 11052, 카드 구매하기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int p[10001], dp[10001];

int main()
{
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
	}

	dp[1] = p[1];
	for (int n = 2; n <= N; n++) {
		dp[n] = p[n];
		for (int i = 1; i <= N - 1; i++) {
			dp[n] = max(dp[n], dp[i] + p[n - i]);
		}
	}

	cout << dp[N];
}