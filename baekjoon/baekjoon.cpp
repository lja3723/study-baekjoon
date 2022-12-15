//problem No. 2529, 부등호
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K, isSelect[60];
char pr[9];
string ansMin, ansMax, tmpAns;

bool checkPr(int i, char cNext) {
	if (pr[i] == '<')
		return tmpAns[i] < cNext;
	else
		return tmpAns[i] > cNext;
}

void BackTrack() {
	if (tmpAns.size() == K + 1) {
		if (ansMin.empty()) 
			ansMin = tmpAns;
		ansMax = tmpAns;
		return;
	}

	for (char i = '0'; i <= '9'; i++) {
		if (!isSelect[i]) {
			if (tmpAns.empty() || checkPr(tmpAns.size() - 1, i)) {
				isSelect[i]++;
				tmpAns.push_back(i);
				BackTrack();
				isSelect[i]--;
				tmpAns.pop_back();
			}
		}
	}
}

int main() {
	cin >> K;
	for (int i = 0; i < K; i++)
		cin >> pr[i];

	for (int i = 0; i < 10; i++)
		BackTrack();

	cout << ansMax << "\n" << ansMin;
}