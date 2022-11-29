//problem No. 9935, 문자열 폭발
#include <iostream>
#include <vector>
using namespace std;

string str, bomb, st;
int i, j;

int main() {
	cin >> str >> bomb;
	int szB = bomb.size();	

	for (i = str.size() - szB; i >= 0; i--) {
		if (str.size() < i + szB)
			continue;
		else if (str.substr(i, szB) == bomb) {
			for (j = 0; j < szB; j++)
				str.pop_back();

			for (j = 0; !st.empty() && j < szB - 1; j++) {
				str.push_back(st.back());
				st.pop_back();
			}
		}
		else {
			st.push_back(str.back());
			str.pop_back();
		}		
	}

	while (!st.empty()) {
		str.push_back(st.back());
		st.pop_back();
	}

	cout << (str.empty() ? "FRULA" : str);
}