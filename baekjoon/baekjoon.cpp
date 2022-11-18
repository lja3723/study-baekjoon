//problem No. 13305, 주유소
#include <iostream>
using namespace std;

int N, city[100000], road[100000];

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++)
		cin >> road[i];
	for (int i = 0; i < N; i++) 
		cin >> city[i];
	
	long long dist = 0, cost = 0, minCity = city[0];
	for (int i = 1; i < N; i++) {
		dist += road[i - 1];
		if (minCity > city[i]) {
			cost += minCity * dist;
			minCity = city[i];
			dist = 0;
		}
	}
	cost += minCity * dist;

	cout << cost;
}
