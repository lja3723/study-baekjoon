//problem No. 11659, 구간 합 구하기 4
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(0);
	int N, M; 
	cin >> N >> M;
	vector<int> v(N + 1);
	vector<int> s(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		s[i] = s[i - 1] + v[i];
	}
	while (M--) {
		int i, j; cin >> i >> j;
		cout << s[j] - s[i - 1] << "\n";
	}
}