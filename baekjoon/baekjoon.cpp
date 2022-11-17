//problem No. 1541, 잃어버린 괄호
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string input, p;
	cin >> input;

	vector<string> sv1;
	stringstream ss1(input);
	while (getline(ss1, p, '-')) //{
		//cout << p << "\n";
		sv1.push_back(p);
	//}

	//cout << "first clear\n\n";

	int sum = 0;
	for (int i = 0; i < sv1.size(); i++) {
		stringstream ss2(sv1[i]);
		while (getline(ss2, p, '+')) //{
			//cout << p << "\n";
			sum += i == 0 ? stoi(p) : -stoi(p);
		//}
	}

	cout << sum;
}
