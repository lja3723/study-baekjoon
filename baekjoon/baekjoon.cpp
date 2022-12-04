﻿//problem No. 1629, 곱셈
#include <iostream>
using namespace std;
typedef long long ll;

long long A, B, C;

long long ans(long long b) {
	if (b == 1)
		return A % C;

	auto tmp = ans(b / 2);

	if (b % 2 == 0)
		return tmp * tmp % C;

	return tmp * ans(b / 2 + 1) % C;
}

int main() {
	cin >> A >> B >> C;

	cout << ans(B);
}