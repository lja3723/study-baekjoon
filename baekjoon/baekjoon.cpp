//problem No. 2294, 동전 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int value[101]; //value[i] == i번째 동전 가치
int dp[10001]; //dp[k] == 동전들의 합이 k의 가치가 있을 때, 동전 수의 최소값 (불가능시 -1)

int main()
{
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> value[i];
	
	fill(dp, dp + 10001, 10000000);
	dp[0] = 0; //0의 가치 == 0개의 동전

	for (int ik = 1; ik <= k; ik++) {
		for (int iv = 1; iv <= n; iv++) {
			if (ik - value[iv] >= 0) {
				dp[ik] = min(dp[ik], dp[ik - value[iv]] + 1);
			}
		}
	}

	cout << (dp[k] == 10000000 ? -1 : dp[k]);
}