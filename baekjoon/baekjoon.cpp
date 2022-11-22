//problem 2565, 전깃줄
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int LIS[101], N, i, a, b;

int main() {
	cin >> N;
	
	for (i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a, b });
	}
	v.push_back({ 0, 0 });
	sort(begin(v), end(v));

	int lis = 0;
	//최장 증가 부분수열을 구함
	for (a = 1; a <= N; a++) {
		LIS[a] = 1;
		for (b = 1; b < a; b++)
			if (v[b].second < v[a].second)
				LIS[a] = max(LIS[a], LIS[b] + 1);

		lis = max(lis, LIS[a]);
	}

	cout << N - lis;
}
