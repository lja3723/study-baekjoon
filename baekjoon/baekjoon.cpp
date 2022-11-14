//problem No. 2667, 단지번호붙이기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
string map[25];
vector<int> total;

void bfs(int Y, int X) {
	if (map[Y][X] == '0') return;
	map[Y][X] = '0';
	
	queue<int> y, x;
	y.push(Y);
	x.push(X);

	int num = 0;
	while (!y.empty()) {
		int yy = y.front(), xx = x.front();
		y.pop(), x.pop();
		num++;

		int dy[4] = { 1, -1, 0, 0 };
		int dx[4] = { 0, 0, 1, -1 };
		for (int i = 0; i < 4; i++) {
			int cy = yy + dy[i];
			int cx = xx + dx[i];

			if (!(0 <= cy && cy < N) || !(0 <= cx && cx < N) || map[cy][cx] == '0') 
				continue;

			map[cy][cx] = '0';
			y.push(cy), x.push(cx);
		}
	}

	total.push_back(num);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> map[i];

	for (int y = 0; y < N; y++) 
		for (int x = 0; x < N; x++)
			bfs(y, x);
	
	sort(total.begin(), total.end());

	cout << total.size() << "\n";

	for (int ans : total) {
		cout << ans << "\n";
	}
}
