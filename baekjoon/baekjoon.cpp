//problem No. 1676, 팩토리얼 0의 개수
#include <iostream>
using namespace std;

int main() {
	int N, d2 = 0, d5 = 0;

	cin >> N;

	for (int n = 1; n <= N; n++) {
		int k = n;
		while (k % 5 == 0) {
			k /= 5;
			d5++;
		}
		while (k % 2 == 0) {
			k /= 2;
			d2++;
		}
	}

	cout << min(d2, d5);
}