//problem No. 1010, 다리 놓기
#include <iostream>
using namespace std;

int combi[30][30];

int getCombi(int M, int N) {
	if (combi[M][N] == 0) {
		combi[M][M] = getCombi(M - 1, N - 1) + getCombi(M - 1, N);
	}

	return combi[M][N];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T, N, M;

	for (M = 1; M < 30; M++) {
		for (N = 0; N <= M; N++) {
			if (0 == N || M == N)
				combi[M][N] = 1;
			else
				combi[M][N] = combi[M - 1][N - 1] + combi[M - 1][N];
		}
	}

	cin >> T;
	while (T--) {
		cin >> N >> M;
		cout << getCombi(M, N) << "\n";
	}
}
