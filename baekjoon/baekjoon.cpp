//problem No. 18111, 마인크래프트
#include <iostream>
using namespace std;

int N, M, B;
int map[500][500];

int main()
{
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	int T = 128e6, H = 0;
	for (int h = 0; h <= 256; h++) {
		int del = 0, add = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int dh = map[i][j] - h;
				if (dh > 0) 
					del += dh; //블럭을 캔다
				else 
					add -= dh; //블럭을 쌓는다				
			}
		}

		if (B + del >= add) { //평지화가 가능함
			int t = 2 * del + add;

			if (t <= T) {
				T = t;
				H = h;
			}
		}
	}

	cout << T << " " << H;
}