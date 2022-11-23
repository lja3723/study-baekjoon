//problem 11054, 가장 긴 바이토닉 부분 수열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dat[1001], N, i, j, LIS[1001], LDS[1001];

int main() {
	cin >> N;

	for (i = 1; i <= N; i++) cin >> dat[i];

	//i가 끝점인 LIS 구하기
	for (i = 1; i <= N; i++) {
		LIS[i] = 1;
		for (j = 1; j < i; j++)
			if (dat[j] < dat[i])
				LIS[i] = max(LIS[i], LIS[j] + 1);
	}

	//i가 시작점인 LDS 구하기
	for (i = N; i >= 1; i--) {
		LDS[i] = 1;
		for (j = N; i < j; j--)
			if (dat[i] > dat[j])
				LDS[i] = max(LDS[i], LDS[j] + 1);
	}

	//i가 최대값인 LBS 구하기
	int ans = 0;
	for (i = 1; i <= N; i++)
		ans = max(ans, LIS[i] + LDS[i] - 1);

	cout << ans;
}
