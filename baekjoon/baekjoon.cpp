//problem No. 17626, Four Squares
#include <iostream>
#include <cmath>
using namespace std;

double sqt[50001];
int ret[50001];
int n;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		sqt[i] = sqrt(i);
	
	ret[1] = 1;
	for (int i = 2; i <= n; i++) {
		int isqt = (int)sqt[i];
		if (sqt[i] - isqt < 10e-10) {
			ret[i] = 1;
		}
		else {
			ret[i] = 2e9;
			for (int j = 1; i - j * j > 0; j++)
				ret[i] = min(ret[i], ret[i - j * j] + 1);
		}
	}

	cout << ret[n];
}