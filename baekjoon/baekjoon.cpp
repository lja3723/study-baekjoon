//problem 11723, 집합
#include <iostream>
using namespace std;

int M, x, S;
string s;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> M;
	while (M--) {
		cin >> s;
		if (!s.compare("add")) {
			cin >> x;
			S |= 1 << x;
		}
		else if (!s.compare("remove")) {
			cin >> x;
			S &= ~(1 << x);
		}
		else if (!s.compare("check")) {
			cin >> x;
			cout << !!(1 << x & S) << "\n";
		}
		else if (!s.compare("toggle")) {
			cin >> x;
			S ^= 1 << x;
		}
		else if (!s.compare("all")) {
			S = ~0;
		}
		else if (!s.compare("empty")) {
			S = 0;
		}
	}
}