//problem No. 1052, 물병
#include <iostream>
#include <queue>
using namespace std;

int N, K, t, i, ans;

int cnt1() {
	t = 0;
	for (i = 0; i < 32; i++)
		if (N & (1 << i))
			t++;
	return t;
}

int r1idx() {
	for (i = 0; i < 32; i++)
		if (N & (1 << i))
			return i;
}

int main() {
	cin >> N >> K;

	while (1) {
		if (cnt1() <= K) {
			cout << ans;
			break;
		}

		ans += 1 << r1idx();
		N += 1 << r1idx();
	}

}