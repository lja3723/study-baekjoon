//problem No. 15686, 치킨 배달
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int N, M, ans = 1e6;
vector<pii> vh, vc; //vh: 집 좌표 //vc: 치킨집 좌표
vector<int> combi; 

int getDistSum() {
	int ret = 0;
	for (pii h : vh) {
		int d = 100;
		for (int i : combi) {
			int dist = abs(h.first - vc[i].first) + abs(h.second - vc[i].second);
			d = min(d, dist);
		}				
		ret += d;
	}

	return ret;
}

void bt() {
	int szv = combi.size();
	if (szv == M) {
		ans = min(ans, getDistSum());
		return;
	}

	for (int i = 0; i < vc.size(); i++) {
		if (szv == 0 || combi[szv - 1] < i) {
			combi.push_back(i);
			bt();
			combi.pop_back();
		}
	}
}

int main()
{
	cin >> N >> M;
	int i, j, d;
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) {
		cin >> d;
		if (d == 1) vh.push_back({ i, j });
		if (d == 2) vc.push_back({ i, j });
	}	
	bt();

	cout << ans;
}