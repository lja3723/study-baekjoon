//problem No. 4179, 불
#include <iostream>
#include <queue>
using namespace std;

const int FR = 0, JH = 1;

struct IJ { int i, j; };

int R, C;
int di[] = { 0, 0, 1, -1 }, dj[] = { 1, -1, 0, 0 };
int vt[2][1000][1000];
string map[1000];
queue<IJ> q[2];


bool isOut(int i, int j) {
	return 0 > i || i >= R || 0 > j || j >= C;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'F') {
				q[FR].push({i, j});
				vt[FR][i][j] = 1;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'J') {
				q[JH].push({i, j});
				vt[JH][i][j] = 1;
				map[i][j] = '.';
			}
		}
	}

	while (!q[JH].empty()) {
		int szFR = q[FR].size(), szJH = q[JH].size();

		while (szJH--) {
			IJ e = q[JH].front(); q[JH].pop();
			if (vt[FR][e.i][e.j])
				continue;

			for (int d = 0; d < 4; d++) {
				int ni = e.i + di[d];
				int nj = e.j + dj[d];

				if (isOut(ni, nj)) {
					cout << vt[JH][e.i][e.j];
					exit(0);
				}

				if (map[ni][nj] == '#' || vt[JH][ni][nj] || vt[FR][ni][nj])
					continue;

				q[JH].push({ ni, nj });
				vt[JH][ni][nj] = vt[JH][e.i][e.j] + 1;
			}
		}

		while (szFR--) {
			IJ e = q[FR].front(); q[FR].pop();
			for (int d = 0; d < 4; d++) {
				int ni = e.i + di[d];
				int nj = e.j + dj[d];

				if (isOut(ni, nj) || map[ni][nj] == '#' || vt[FR][ni][nj])
					continue;

				q[FR].push({ ni, nj });
				vt[FR][ni][nj] = 1;
			}
		}		
	}

	cout << "IMPOSSIBLE";
}