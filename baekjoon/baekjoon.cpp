//problem No. 1074, Z
#include <iostream>
#include <cmath>
using namespace std;

int N, R, C;
int ans = 0;

void func(int n, int r, int c) {
	if (n == 1) {
		cout << ans;
		return;
	}

	int nn = n / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			int nr = r + i * nn;
			int nc = c + j * nn;

			if (nr <= R && R < nr + nn) {
				if (nc <= C && C < nc + nn) {
					ans += (2 * i + j) * nn * nn;
					func(nn, nr, nc);
					return;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> R >> C;
	func(pow(2, N), 0, 0);
}