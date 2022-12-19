//problem No. 12873, 기념품
#include <iostream>
#include <list>
#include <queue>
using namespace std;
long long caseT, shout;
int N;

int main() {
	cin >> N;
	queue<int> q;

	for (int i = 1; i <= N; i++)
		q.push(i);

	for (caseT = 1;; caseT++)  {
		if (q.size() == 1) {
			cout << q.front();
			exit(0);
		}

		shout = (caseT * caseT * caseT - 1);
		shout %= q.size();

		while (shout--) {
			q.push(q.front());
			q.pop();
		}

		q.pop();
	}
}