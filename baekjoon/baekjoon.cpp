//problem No. 16953, A → B
#include <iostream>
using namespace std;

int a, b;

int main() {
	cin >> a >> b;
	int cnt = 0;
	while (a < b) {
		if (b % 2 == 0) {
			cnt++;
			b /= 2;
		}
		else if ((b - 1) % 10 == 0) {
			cnt++;
			b /= 10;
		}
		else {
			cout << "-1";
			return 0;
		}
	}

	if (a == b)
		cout << cnt + 1;
	else
		cout << "-1";
}
