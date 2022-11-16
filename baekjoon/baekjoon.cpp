//problem No. 11053, 가장 긴 증가하는 부분 수열
#include <iostream>
#include <vector>
using namespace std;
 
int N, i, j;
int A[1001];
int dp[1001];

int main() {
	cin >> N;
	for (i = 1; i <= N; i++) cin >> A[i];

	int ans = 0;
	for (i = 1; i <= N; i++) {
		dp[i] = 1;
		for (j = 1; j < i; j++) 
			if (A[j] < A[i]) 
				dp[i] = max(dp[i], dp[j] + 1);		

		ans = max(ans, dp[i]);
	}

	cout << ans;
}
