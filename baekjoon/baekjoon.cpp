//problem No. 2559, 수열
#include <iostream>
using namespace std;

int N, K, i, ans = -1e9, dat[100001];

int main() {
	cin >> N >> K;
	for (i = 1; i <= N; i++) {
		cin >> dat[i];
		dat[i] += dat[i - 1];
	}

	for (i = K; i <= N; i++) 
		ans = max(ans, dat[i] - dat[i - K]);
	
	cout << ans;
}