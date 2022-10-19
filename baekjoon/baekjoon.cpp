//problem No. 1744, 수 묶기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N; cin >> N;
	vector<int> p, n;
	int cnt[2] = { 0 };

	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		if (k > 1)
			p.push_back(k);
		else if (k < 0)
			n.push_back(k);
		else
			cnt[k]++;
	}

	sort(p.begin(), p.end(), greater<int>());
	sort(n.begin(), n.end());

	int sum = 0, i;
	for (i = 0; i + 1 < p.size(); i += 2)
		sum += p[i] * p[i + 1];
	if (i == p.size() - 1)
		sum += p[i];	
	for (i = 0; i + 1 < n.size(); i += 2)
		sum += n[i] * n[i + 1];
	if (i == n.size() - 1 && cnt[0] == 0)
		sum += n[i];
	sum += cnt[1];

	cout << sum;
}