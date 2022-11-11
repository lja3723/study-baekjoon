//problem No. 1759, 암호 만들기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> c;
vector<char> ans;

void bt() {
	if (ans.size() == L) {
		int cnt = 0;
		for (char a : ans) for (char c : "aeiou")
			if (a == c) cnt++;

		if (cnt > 0 && (L - cnt) > 1) {
			for (char a : ans) cout << a;
			cout << "\n";
		}

		return;
	}

	for (int i = 0; i < C; i++)
		if (ans.empty() || ans[ans.size() - 1] < c[i]) {
			ans.push_back(c[i]);
			bt();
			ans.pop_back();
		}
}

int main()
{
	cin >> L >> C;
	c.resize(C);
	for (int i = 0; i < C; i++)
		cin >> c[i];
	sort(c.begin(), c.end());

	bt();
}