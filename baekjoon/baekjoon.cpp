//problem No. 1463, 1로 만들기
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001] = { 0, 0, 1, 1 }, N;

int getMin(int N) {
	int& r = dp[N];
	if (N < 2)
		return 0;

	if (r == 0) {
		r = getMin(N - 1) + 1;

		if (N % 2 == 0) {
			r = min({ r, getMin(N / 2) + 1 });
		}

		if (N % 3 == 0) {
			r = min({ r, getMin(N / 3) + 1 });
		}
	}

	return r;
}

int main()
{
	cin >> N;
	cout << getMin(N);
}