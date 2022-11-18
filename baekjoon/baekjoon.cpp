//problem No. 12865, 평범한 배낭
#include <iostream>
#include <vector>
using namespace std;

int N, K;
int obj[101][2];
int dp[101][100001]; //dp[n][k] 무게 k 이내에 n개의 보석을 골랐을 때 이익의 최대값

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> obj[i][0] >> obj[i][1]; //w, v;
	}

	for (int n = 1; n <= N; n++)
		for (int k = 1; k <= K; k++)
			if (k < obj[n][0])
				dp[n][k] = dp[n - 1][k];
			else
				dp[n][k] = max(obj[n][1] + dp[n - 1][k - obj[n][0]], dp[n - 1][k]);

	cout << dp[N][K];
}
