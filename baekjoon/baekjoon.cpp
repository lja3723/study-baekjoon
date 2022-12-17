//problem No. 2573, 빙산
#include <iostream>
#include <list>
#include <queue>
using namespace std;

struct IJ { int i, j; };

list<IJ> ice;
int map[300][300], tmp[300][300];
int di[] = { 0, 0, 1, -1 }, dj[] = { 1, -1, 0, 0 };
int N, M;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j])
				ice.push_back({ i, j });
		}

	for (int year = 0;; year++) {
		//빙산 수 세기 전 방문배열 초기화
		fill(&tmp[0][0], &tmp[299][299] + 1, 0);

		//빙산 수 세기(use bfs)
		int iceCnt = 0;
		for (auto& e : ice) {
			if (!tmp[e.i][e.j]) {
				//빙산이 분리됐으므로 답 출력
				if (++iceCnt > 1) {
					cout << year;
					exit(0);
				}

				queue<IJ> q;
				q.push(e);
				tmp[e.i][e.j] = 1;

				while (!q.empty()) {
					IJ c = q.front(); q.pop();

					for (int d = 0; d < 4; d++) {
						int ni = c.i + di[d];
						int nj = c.j + dj[d];
						if (!tmp[ni][nj] && map[ni][nj] > 0) {
							q.push({ ni, nj });
							tmp[ni][nj] = 1;
						}
					}
				}
			}
		}

		//녹는 얼음의 양 계산
		for (auto& e : ice) {
			tmp[e.i][e.j] = 0;

			for (int d = 0; d < 4; d++) {
				int ni = e.i + di[d];
				int nj = e.j + dj[d];
				if (map[ni][nj] == 0)
					tmp[e.i][e.j]++;
			}
		}

		//얼음을 녹임
		auto it = ice.begin();
		while (it != ice.end()) {
			int i = it->i, j = it->j;
			map[i][j] -= tmp[i][j];
			if (map[i][j] <= 0) {
				map[i][j] = 0;
				it = ice.erase(it);

				//끝내 얼음이 다 녹았으므로 0 출력
				if (ice.empty()) {
					cout << 0;
					exit(0);
				}
			}
			else it++;
		}
	}
}