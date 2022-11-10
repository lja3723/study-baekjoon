//problem No. 15829, Hashing
#include <iostream>
using namespace std;

int N, M;
vector<int> trees;

int main()
{
	int L;
	cin >> L;

	string s;
	cin >> s;

	long long H = 0, p1 = 31, p2 = 1234567891;
	for (int i = 0; i < s.size(); i++) {
		long long a = s[i] - 'a' + 1;
		int j = i;
		while (j--) {
			a *= p1;
			a %= p2;
		}
		H += a;
		H %= p2;
	}

	cout << H % p2;
}