//problem 11722, 가장 긴 감소하는 부분 수열
#include <iostream>
using namespace std;

int dat[1001], N, i, j, LDS[1001];

int main() {
	cin >> N;
	
	for (i = 1; i <= N; i++) 
		cin >> dat[i];

	int ans = 0;
	for (i = 1; i <= N; i++) {
		LDS[i] = 1;
		for (j = 1; j < i; j++)
			if (dat[j] > dat[i])
				LDS[i] = max(LDS[i], LDS[j] + 1);
		ans = max(ans, LDS[i]);
	}

	cout << ans;
}
