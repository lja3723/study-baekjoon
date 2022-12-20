//problem No. 5014, 스타트링크
#include <iostream>
#include <queue>
using namespace std;

int v[1000001];
int F, S, G, U, D;

int main() {
	cin >> F >> S >> G >> U >> D;
	for (int i = 1; i <= F; i++)
		v[i] = -1;

	queue<int> q;
	q.push(S);
	v[S] = 0;

	while (!q.empty()) {
		int f = q.front(); q.pop();

		if (f == G) {
			cout << v[f];
			exit(0);
		}
		int nU = f + U;
		int nD = f - D;
		if (nU <= F && v[nU] == -1) {
			v[nU] = v[f] + 1;
			q.push(nU);
		}
		if (1 <= nD && v[nD] == -1) {
			v[nD] = v[f] + 1;
			q.push(nD);
		}
	}

	cout << "use the stairs";
}