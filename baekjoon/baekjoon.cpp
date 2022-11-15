//problem No. 5430, AC
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;
 
int main() { 
	int T; cin >> T;
	while (T--) {
		string p; cin >> p;
		int n; cin >> n;
		string sdat; cin >> sdat;

		sdat = sdat.substr(1, sdat.size() - 2);
		stringstream ss(sdat);
		string sd;
		deque<int> dq;
		while (getline(ss, sd, ','))
			dq.push_back(stoi(sd));

		int isR = 0, isE = 0;
		for (char c : p) {
			if (c == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					isE = 1;
					break;
				}
				else if (!isR)
					dq.pop_front();
				else
					dq.pop_back();
			}
			else
				isR = !isR;
		}

		if (!isE) {
			cout << "[";
			while (!dq.empty()) {
				if (!isR) {
					cout << dq.front();
					dq.pop_front();
				}
				else {
					cout << dq.back();
					dq.pop_back();
				}

				if (!dq.empty())
					cout << ',';
			}

			cout << "]\n";
		}
	}
}
