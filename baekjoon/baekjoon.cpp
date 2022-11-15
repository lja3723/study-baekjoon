//problem No. 1149, RGB거리
#include <iostream>
#include <algorithm>
using namespace std;

int N, n, i;
int rgb[3]; 
int dpa[3], dpb[3];

int main() {
	cin >> N;
	for (n = 0; n < N; n++) 

	for (n = 0; n < N; n++) {
		cin >> rgb[0] >> rgb[1] >> rgb[2];
		if (n == 0)
			for (i = 0; i < 3; i++) 
				dpa[i] = rgb[i];
		else {
			dpb[0] = min(dpa[1], dpa[2]) + rgb[0];
			dpb[1] = min(dpa[0], dpa[2]) + rgb[1];
			dpb[2] = min(dpa[0], dpa[1]) + rgb[2];
			for (i = 0; i < 3; i++)
				dpa[i] = dpb[i];
		}
	}

	cout << min({ dpb[0], dpb[1], dpb[2] });
}