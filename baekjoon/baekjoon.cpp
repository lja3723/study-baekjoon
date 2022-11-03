//problem No. 1202, 보석 도둑
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct jewel {
	int m; //무게
	int v; //가치
};

//가치 높은 순 우선순위 큐의 조건자
struct pr {
	bool operator()(jewel& l, jewel& r) {
		return l.v < r.v;
	}
};

vector<jewel> jewels; 
vector<int> bags;
//가치 높은 순 우선순위 큐
priority_queue<jewel, vector<jewel>, pr> pq; 

int main()
{
	int N, K;
	cin >> N >> K;
	jewels.resize(N);
	bags.resize(K);

	for (int i = 0; i < N; i++)
		cin >> jewels[i].m >> jewels[i].v;
	for (int i = 0; i < K; i++) {
		cin >> bags[i];
	}

	// 무게 오름차순
	sort(jewels.begin(), jewels.end(), 
		[](auto& l, auto& r) { return l.m < r.m; }
	);
	sort(bags.begin(), bags.end());

	int j = 0;
	long ret = 0;
	for (int k = 0; k < K; k++) {
		//k번째로 작은 가방에 들어갈 수 있는 모든 보석을 pq에 넣음
		while (j < N && jewels[j].m <= bags[k])
			pq.push(jewels[j++]);

		//가장 가치있는 보석을 담음
		if (!pq.empty()) {
			ret += pq.top().v;
			pq.pop();
		}
	}

	cout << ret;
}