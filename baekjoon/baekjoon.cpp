//problem No. 16236, 아기 상어
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Pos { int i, j; };

Pos shark, goal;
int N, i, j, szShark = 2, dist;
int map[20][20];

//bfs
//먹기 가능 물고기를 찾으면 set goal & dist
//못 먹으면 return false
bool findFish() {
	queue<Pos> q;
	int vt[20][20];

	//vt 초기화
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (szShark < map[i][j])
				vt[i][j] = 100; //못 먹는 물고기
			else if (0 < map[i][j] && map[i][j] < szShark)
				vt[i][j] = -1; //먹기 가능
			else
				vt[i][j] = -2; //빈공간
		}
	}

	q.push(shark);
	vt[shark.i][shark.j] = 0;

	dist = 0;
	vector<Pos> fishList;
	while (!q.empty()) {
		Pos f = q.front(); q.pop();

		//먹을 수 있는 최소 거리의 물고기 탐색이 끝남
		if (dist && vt[f.i][f.j] == dist) break;

		int di[] = {-1, 1, 0, 0};
		int dj[] = {0, 0, -1, 1};
		for (int d = 0; d < 4; d++) {
			int ni = f.i + di[d];
			int nj = f.j + dj[d];

			if (!(0 <= ni && ni < N) || !(0 <= nj && nj < N))
				continue;
			if (vt[ni][nj] >= 0)
				continue;

			if (vt[ni][nj] == -1) {
				if (!dist) //set dist
					dist = vt[f.i][f.j] + 1; //앞으로 dist만큼 떨어진 곳만 탐색
				fishList.push_back({ ni, nj });
			}

			q.push({ ni, nj });
			vt[ni][nj] = vt[f.i][f.j] + 1;
		}
	}

	if (!fishList.empty()) {
		sort(fishList.begin(), fishList.end(), 
			[](Pos l, Pos r) {
				if (l.i != r.i) 
					return l.i < r.i;
				else 
					return l.j < r.j;
			}
		);
		goal = fishList[0]; //set goal

		return true;
	}
	else
		return false; //먹을 수 없음
}


int main() {
	cin >> N;
	//initMap
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				shark = { i, j };
			}
		}
	}

	//simulate
	int time = 0;
	int eatCnt = 0;
	while (1) {
		if (!findFish()) break;

		time += dist;
		map[goal.i][goal.j] = 0;
		shark = goal;
		if (++eatCnt >= szShark) {
			eatCnt = 0;
			szShark++;
		}
	}

	cout << time;
}
