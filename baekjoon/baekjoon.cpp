//problem No. 15650, N과 M (2)
#include <iostream>
#include <vector>
using namespace std;
int N, M;

void bt(int lv) {
	static int a[8];
	static int idx;

	if (lv == M) {
		for (int i = 0; i < lv; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int n = 1; n <= N; n++) {
		if (idx != 0) {
			if (a[idx - 1] >= n)
				continue;
		}
		a[idx++] = n;
		bt(lv + 1);
		idx--;
	}
}

int main()
{
	cin >> N >> M;
	bt(0);
}