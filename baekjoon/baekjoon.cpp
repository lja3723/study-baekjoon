//problem No. 14226, 이모티콘
#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

//t초에 act를 했고, dp개가 출력되며, 클립보드에 cp개 있음
struct Stat { int dp, cp; };

int S, tDp[MAX];
bool visit[MAX][MAX];
queue<Stat> q;

int main() {
	fill(tDp, tDp + MAX, -1);

	cin >> S;
	q.push({ 1, 0 });
	visit[1][0] = 1;

	int t = 0;
	while (tDp[S] == -1 && !q.empty()) {
		int sz = q.size();
		while (sz--) {
			Stat s = q.front(); q.pop();

			if (tDp[s.dp] == -1) {
				tDp[s.dp] = t;
				if (s.dp == S)
					break;
			}

			//1.
			if (!visit[s.dp][s.dp]) {
				q.push({ s.dp, s.dp });
				visit[s.dp][s.dp] = 1;
			}

			//2.
			int nxtDp = s.dp + s.cp;
			if (nxtDp < MAX && !visit[nxtDp][s.cp]) {
				q.push({ nxtDp, s.cp });
				visit[nxtDp][s.cp] = 1;
			}

			//3.
			nxtDp = s.dp - 1;
			if (nxtDp > 0 && !visit[nxtDp][s.cp]) {
				q.push({ nxtDp, s.cp });
				visit[nxtDp][s.cp] = 1;
			}
		}
		t++;
	}

	cout << tDp[S];
}