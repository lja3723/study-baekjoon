//problem No. 1461, 도서관
#include <iostream>
using namespace std;

int N, M, i, j;
vector<int> books[2]; //books[0]: 음수(절대값), books[1]: 양수

int main()
{
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> j;
		books[j > 0].push_back(j > 0 ? j : -j);
		//j > 0의 판정(true->1, false->0)에 따라 books가 선택됨
		//j가 음수인 경우 -j(절대값) 저장
	}

	for (i = 0; i < 2; i++) {
		//각 저장소에 0(추후 books[i].back() 했을 경우 empty()인 상태를 방지)을 저장 후 정렬
		books[i].push_back(0);
		sort(books[i].begin(), books[i].end());
	}

	int ans = 0;
	int bb[2]; //BooksBack, bb[0]과 [1]은 각각 음수, 양수들 중 절대값이 가장 큰 수를 저장함
	for (i = 0; i < 2; i++) {
		bb[i] = books[i].back();
		int len = books[i].size();

		//books[i]의 절대값이 가장 큰 원소부터 M씩 앞으로 차례대로 방문
		//ex: 0 4 7 8 12 15 19 34 36 39 , M == 3이면
		//책을 1~M권 챙긴 후 39, 19, 8을 방문 후 돌아오는 것이 최적해임
		for (j = len - 1; j > 0; j -= M)
			ans += 2 * books[i][j];
	}

	//마지막 for문에서, 마지막 책을 두고 다시 0으로 돌아왔으므로
	//bb[0], [1]중 절대값이 더 큰 곳의 방문을 무효화 함
	cout << ans - bb[bb[0] < bb[1]];
}