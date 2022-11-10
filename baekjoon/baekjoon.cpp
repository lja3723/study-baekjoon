//problem No. 2805, 나무 자르기
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> trees;

int main()
{
	cin >> N >> M;
	while (N--) {
		int d; cin >> d;
		trees.push_back(d);
	}

	int f = 0, l = 1e9, h;
	while (f <= l) {
		h = (f + l) / 2;
		long long get = 0;
		for (int t : trees) {
			int d = t - h;
			if (d < 0) d = 0;
			get += d;
		}

		if (get < M)
			l = h - 1;
		else
			f = h + 1;
	}

	cout << l;
}