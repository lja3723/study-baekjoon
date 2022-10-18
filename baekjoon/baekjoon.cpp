//problem No. 24060, 알고리즘 수업 - 병합 정렬 1
#include <iostream>
#include <vector>
using namespace std;
int cnt, K, out;

void merge(vector<int>& v, int p, int q, int r) 
{
	vector<int> tmp(r - p + 1);
	int i = p, j = q + 1, t = 0;
	while (i <= q && j <= r) {
		if (v[i] <= v[j]) {
			tmp[t++] = v[i++];
		}
		else {
			tmp[t++] = v[j++];
		}
	}
	while (i <= q)
		tmp[t++] = v[i++];
	while (j <= r)
		tmp[t++] = v[j++];
	i = p, t = 0;
	while (i <= r) {
		v[i++] = tmp[t++];
		if (++cnt == K) {
			out = v[i - 1];
		}
	}
}

void merge_sort(vector<int>& v, int p, int r)
{
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(v, p, q);
		merge_sort(v, q + 1, r);
		merge(v, p, q, r);
	}
}

int main()
{
	cin.tie(0);

	int N; cin >> N >> K;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	merge_sort(v, 0, N - 1);
	if (K > cnt) out = -1;
	cout << out;
}