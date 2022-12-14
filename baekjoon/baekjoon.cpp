//problem No. 14503, 로봇 청소기
#include <iostream>
using namespace std;

int N, M;
int R, C, D; //로봇청소기의 현재 좌표 & 방향
int map[50][50];

//d(X)[i][j]: i방향을 향할때, X쪽의 좌표(r,c) = (j=0, j=1)
int dLeft[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int dFront[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int main()
{
	cin >> N >> M >> R >> C >> D;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	int ans = 0, able = 1;
	while (1) {
		if (able) {
			map[R][C] = -1; //청소함
			ans++;
			able = 0;
		}

		for (int d = 0; !able && d < 4; d++) {
			if (map[R + dLeft[D][0]][C + dLeft[D][1]] == 0)
				able = 1;

			if (--D == -1) D = 3; //turn left
		}

		if (able) {
			R += dFront[D][0];
			C += dFront[D][1];
		}
		else if (map[R - dFront[D][0]][C - dFront[D][1]] != 1) {
			R -= dFront[D][0];
			C -= dFront[D][1];
		}
		else break;
	}

	cout << ans;
}