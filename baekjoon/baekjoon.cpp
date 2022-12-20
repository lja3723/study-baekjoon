﻿//problem No. 24508, 나도리팡
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, T, i;
vector<int> b;

int main() {
	cin >> N >> K >> T;

	b.resize(N);
	for (i = 0; i < N; i++)
		cin >> b[i];
	sort(begin(b), end(b), greater<int>());

	int f = 0, l = N - 1;
	while (f < l && 0 <= T) {
		int need = K - b[f];
		if (b[l] <= need) {
			b[f] += b[l];
			T -= b[l];
			b[l--] = 0;
		}
		else {
			b[f++] += need;
			T -= need;
			b[l] -= need;
		}
	}

	if (T >= 0 && (b[f] == K || b[f] == 0))
		cout << "YES";
	else
		cout << "NO";
}