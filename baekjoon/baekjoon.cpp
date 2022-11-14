//problem No. 1697, 숨바꼭질
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct PT { int p, t; }; //위치 & 시간
int visited[100001];
int n, k, ans;

void bfs() {
	if (n == k) return;

	queue<PT> q;
	q.push({ n, 0 });
	visited[n]++;

	while (true) {
		PT now = q.front();
		q.pop();

		int i, nt = now.t + 1;
		int np[3] = { now.p + 1, now.p - 1, 2 * now.p };
		for (i = 0; i < 3; i++) {
			if (!(0 <= np[i] && np[i] <= 100000) || visited[np[i]])
				continue;

			if (np[i] == k) {
				ans = nt;
				return;
			}

			q.push({ np[i], nt });
			visited[np[i]]++;
		}
	}
}

int main()
{
	cin >> n >> k;
	bfs();
	cout << ans;
}
