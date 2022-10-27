//problem No. 1966, 프린터 큐
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int pCnt = 0; //프린트 카운터

		[&pCnt]() {
			int N, M; cin >> N >> M;
			queue<pair<int, bool>> q; //first:문서 우선순위, second:관찰대상 문서 여부
			int p[10] = { 0 }; //우선순위 카운팅 배열
			int pIdx = 9; //가장 큰 우선순위 포인팅 인덱스

			for (int i = 0; i < N; i++) {
				int k; cin >> k;
				bool sel = false;

				if (i == M) sel = true; //관찰대상 문서를 마킹
				p[k]++;
				q.push(make_pair(k, sel));
			}

			while (!q.empty()) {
				// 가장 큰 우선순위를 가리킬 때까지 인덱스 감소
				while (0 <= pIdx && p[pIdx] == 0) pIdx--;

				auto& f = q.front();
				if (f.first == pIdx) {
					q.pop();
					p[pIdx]--;
					pCnt++;

					//관찰 대상 문서였다면 시뮬레이션 종료
					if (f.second) return;
				}
				else {
					q.push(f);
					q.pop();
				}
			}
		}();

		cout << pCnt << "\n";
	}
}