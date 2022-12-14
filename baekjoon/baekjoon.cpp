//problem No. 1992, 쿼드트리
#include <iostream>
using namespace std;

int N;
string map[64];

bool isEqual(int bi, int bj, int len) {
	for (int i = bi; i < bi + len; i++)
		for (int j = bj; j < bj + len; j++)
			if (map[i][j] != map[bi][bj])
				return false;

	return true;
}

string QuadTree(int bi, int bj, int len) {
	string ret;
	if (isEqual(bi, bj, len)) {
		ret = map[bi][bj];
		return ret;
	}

	ret = "(";
	len /= 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			ret += QuadTree(bi + i * len, bj + j * len, len);

	return ret + ")";
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	cout << QuadTree(0, 0, N);
}