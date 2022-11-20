//problem No. 2193, 이친수
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long dp[91][2];

/*
 \  0  1  2  3  4  5  6  7  8
0 | 0  0  1  
1 | 0  1  0  


10 0

10 1

100 0
101 0

100 1


1000 0
1001 0
1010 0

1000 1

*/

int main() {
	cin >> n;

	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[2][0] = 1;
	dp[2][1] = 0;

	for (int i = 3; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[n][0] + dp[n][1];
}
