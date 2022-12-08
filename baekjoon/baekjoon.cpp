//problem No. 2580, 스도쿠
#include <iostream>
#include <vector>
using namespace std;

struct RC { int r, c; };
int map[9][9], rowCheck[9][10], colCheck[9][10], boxCheck[9][10];
vector<RC> blank;

int boxIdx(int i, int j) {
	return 3 * (i / 3) + (j / 3);
}

void checkExist(int i, int j, int n, int flag) {
	rowCheck[i][n] += flag;
	colCheck[j][n] += flag;
	boxCheck[boxIdx(i, j)][n] += flag;
}

void bt(int filled) {
	if (blank.empty()) return;
	if (filled == blank.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << map[i][j] << " ";
			cout << "\n";
		}
		exit(0);
	}

	RC cur = blank[filled];
	for (int n = 1; n <= 9; n++) {
		if (!rowCheck[cur.r][n] && !colCheck[cur.c][n] && !boxCheck[boxIdx(cur.r, cur.c)][n]) {
			map[cur.r][cur.c] = n;
			checkExist(cur.r, cur.c, n, 1);
			bt(filled + 1);
			map[cur.r][cur.c] = 0;
			checkExist(cur.r, cur.c, n, -1);
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) 
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			checkExist(i, j, map[i][j], 1);
			if (map[i][j] == 0)
				blank.push_back({ i, j });
		}

	bt(0);
}
