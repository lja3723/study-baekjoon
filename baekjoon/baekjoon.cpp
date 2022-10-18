//problem No. 15651, N과 M (3)
#include <iostream>
#include <vector>
using namespace std;

void bt(int N, int M, int d) {
	static int a[8];
	static int idx;

	if (d == M) {
		for (int i = 0; i < d; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int n = 1; n <= N; n++) {
		a[idx++] = n;
		bt(N, M, d + 1);
		idx--;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	bt(N, M, 0);
}