//problem No. 1743, 음식물 피하기
#include <iostream>
using namespace std;

int N, M, K;
int dat[101][101];
int local, ans;

void dfs(int i, int j) {
	if (!(1 <= i && i <= N)) return;
	if (!(1 <= j && j <= M)) return;
	if (dat[i][j] == 0) return;

	local++;
	dat[i][j] = 0;
	dfs(i + 1, j);
	dfs(i - 1, j);
	dfs(i, j + 1);
	dfs(i, j - 1);
}

int main()
{
	cin >> N >> M >> K;
	while (K--) {
		int r, c;
		cin >> r >> c;
		dat[r][c] = 1;
	}	

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
		{
			if (dat[i][j] == 1) {
				dfs(i, j);
				ans = ans < local ? local : ans;
				local = 0;
			}
		}
	}
			
	cout << ans;
}