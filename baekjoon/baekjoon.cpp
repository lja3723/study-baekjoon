//problem No. 9252, LCS 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][1001], i, j;
string a, b, ans;

int main() {
	cin >> a >> b;
	a = " " + a;
	b = " " + b;
	for (i = 1; i < a.size(); i++)
		for (j = 1; j < b.size(); j++)
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

	i = a.size() - 1;
	j = b.size() - 1;
	while (dp[i][j] != 0) {

		if (dp[i][j] == dp[i - 1][j])
			i--;
		else if (dp[i][j] == dp[i][j - 1])
			j--;
		else {
			ans.push_back(a[i]);
			i--, j--;
		}
	}
	reverse(begin(ans), end(ans));

	cout << dp[a.size() - 1][b.size() - 1] << "\n" << ans;

}