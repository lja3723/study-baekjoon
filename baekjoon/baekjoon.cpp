//problem No. 1655, 가운데를 말해요
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	priority_queue<int> pqL;
	priority_queue<int, vector<int>, greater<int>> pqR;

	while (N--) {
		int d; cin >> d;

		if (pqL.empty() || d <= pqL.top())
			pqL.push(d);
		else
			pqR.push(d);

		if (pqL.size() >= pqR.size() + 2) {
			pqR.push(pqL.top());
			pqL.pop();
		}
		else if (pqL.size() + 1 <= pqR.size()) {
			pqL.push(pqR.top());
			pqR.pop();
		}

		cout << pqL.top() << "\n";
	}
}
