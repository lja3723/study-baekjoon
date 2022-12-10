//problem No. 7662, 이중 우선순위 큐
#include <iostream>
#include <set>
using namespace std;

void sol() {
	multiset<long long> ms;
	int Q; cin >> Q;
	while (Q--) {
		char c;
		long long d;
		cin >> c >> d;
		if (c == 'I')
			ms.insert(d);
		else if (!ms.empty()) {
			if (d == 1)
				ms.erase(--ms.end());
			else
				ms.erase(ms.begin());
		}
	}
	
	if (!ms.empty())
		cout << *(--ms.end()) << " " << *ms.begin() << "\n";
	else
		cout << "EMPTY\n";
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int T; cin >> T;
	while (T--) sol();
}