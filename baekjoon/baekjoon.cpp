//problem No. 1012, 유기농 배추
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 2500
using namespace std;

int M, N, K;
bool dat[50][50];
bool graph[MAX][MAX];

void dfs(int m, int n) {
	dat[m][n] = false;

	if (0 < m		&& dat[m - 1][n] == true) dfs(m - 1, n);
	if (m < M - 1	&& dat[m + 1][n] == true) dfs(m + 1, n);
	if (0 < n		&& dat[m][n - 1] == true) dfs(m, n - 1);
	if (n < N - 1	&& dat[m][n + 1] == true) dfs(m, n + 1);
}

int main()
{
	int T;
	cin >> T;

	while (T--) {
		int cnt = 0;
		for (int i = 0; i < 50; i++)
			fill(dat[i], dat[i] + 50, false);

		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int m, n;
			cin >> m >> n;
			dat[m][n] = true;
		}

		for (int m = 0; m < M; m++)
			for (int n = 0; n < N; n++) {
				if (dat[m][n] == true) {
					dfs(m, n);
					cnt++;
				}
			}

		cout << cnt << "\n";
	}
}