//problem No. 9019, DSLR
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, A, B;
string cmd = "DSLR";

int next(int c, int n) {
	switch (c) {
	case 0: //cmd D
		return n * 2 % 10000;
	case 1: //cmd S
		return --n == -1 ? 9999 : n;
	case 2: //cmd L
		return n / 1000 + n % 1000 * 10;
	case 3: //cmd R
		return n / 10 + n % 10 * 1000;
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < 4; i++) {
		cout << next(i, T) << " ";
	}
	/*
	while (T--) {
		cin >> A >> B;

		vector<int> visit(10000, 0);
		queue<pair<int, string>> q;

		q.push({ A, "" });
		visit[A] = 1;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			if (cur.first == B) {
				cout << cur.second << "\n";
				break;
			}

			for (int c = 0; c < 4; c++) {
				if (visit[next(c, cur.first)])
					continue;
				q.push({ next(c, cur.first), cur.second + cmd[c]});
				visit[next(c, cur.first)] = 1;
			}
		}
	}
	*/
}