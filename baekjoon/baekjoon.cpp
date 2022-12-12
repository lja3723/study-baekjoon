//problem No. 1780, 종이의 개수
#include <iostream>
using namespace std;

int N;
int m[2187][2187], ans[3];

void solve(int si, int sj, int len) {
	if (len == 1) {
		ans[1 + m[si][sj]]++;
		return;
	}

	int initVal = m[si][sj], isEqual = 1;
	for (int i = si; isEqual && i < si + len; i++)
		for (int j = sj; isEqual && j < sj + len; j++)
			if (initVal != m[i][j])
				isEqual = 0;

	if (isEqual) {
		ans[1 + initVal]++;
		return;
	}

	len /= 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			solve(si + i * len, sj + j * len, len);			
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> m[i][j];

	solve(0, 0, N);
	for (int i = 0; i < 3; i++)
		cout << ans[i] << "\n";
}