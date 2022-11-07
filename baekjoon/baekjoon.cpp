//problem No. 1654, 랜선 자르기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dat;

int main()
{
	int K, N, n;
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> n;
		dat.push_back(n);
	}

	long long f = 1, l = 2147483647, m, ans = 0;
	while (f <= l) {
		m = (f + l) / 2;
		n = 0;
		for (auto i : dat) {
			n += i / m;
		}

		if (n < N)
			l = m - 1;
		else {
			ans = (ans > m ? ans : m);
			f = m + 1;
		}
	}

	cout << ans;
}