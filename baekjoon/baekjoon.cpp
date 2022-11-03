//problem No. 11403, 경로 찾기
#include <iostream>
using namespace std;

int N;
int dat[100][100];
int visited[100];
int ret[100][100];	

void dfs(int V) {
	for (int u = 0; u < N; u++) {
		if (dat[V][u] == 1 && !visited[u]) {
			visited[u] = 1;
			dfs(u);
		}
	}
}

int main()
{
	//입력
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> dat[i][j];

	for (int v = 0; v < N; v++) {
		dfs(v);

		for (int u = 0; u < N; u++) {
			ret[v][u] = visited[u]; //결과값 ret에 저장
			visited[u] = 0;	//visited 초기화
		}
	}

	//출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << ret[i][j] << " ";
		cout << "\n";
	}
}