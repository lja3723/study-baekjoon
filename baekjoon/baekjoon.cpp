//problem No. 17626, Four Squares
#include <iostream>
#include <cmath>
using namespace std;

long long sq[50001];
long long ret[50001];
int n;

int main() {
	cin >> n;
	
	ret[1] = 1;
	for (int i = 2; i <= n; i++) {
		double s = sqrt(i);
		if (s - (int)s < 10e-10) {
			ret[i] = 1;
		}
		else {
			ret[i] = ret[i - (int)s * (int)s] + 1;
		}
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << i << ": " << ret[i] << endl;
	//}
	cout << ret[n];
}