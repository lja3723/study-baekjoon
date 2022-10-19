//problem No. 9663, N-Queen
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void NQueen(int N, int& cnt, int depth) {
	static int q[15];

	if (depth < N) {
		for (int n = 0; n < N; n++) {
			bool able = [depth, n]() {
				for (int j = 0; j < depth; j++) {
					if (n == q[j] || abs(n - q[j]) == depth - j) {
						return false;
					}
				}
				return true;
			}();

			if (able) {
				q[depth] = n;
				NQueen(N, cnt, depth + 1);
			}
		}
	}
	else {
		cnt++;
	}


}

int main()
{
	int N, cnt = 0;
	cin >> N;
	NQueen(N, cnt, 0);
	cout << cnt;
}