//problem No. 1005, ACM Craft
#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

int T, N, K, W, D[MAX], minTime[MAX];
vector<int> preBuildings[MAX];

int getMinTime(int V) {
    if (minTime[V] != -1)
        return minTime[V];

    if (preBuildings[V].empty())
        return minTime[V] = D[V];

    int maxTime = -1;
    for (int u : preBuildings[V])
        maxTime = max(maxTime, getMinTime(u));

    return minTime[V] = maxTime + D[V];
}

void solution() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> D[i];
        preBuildings[i].clear();
    }
    for (int i = 0; i < K; i++) {
        int X, Y;
        cin >> X >> Y;
        preBuildings[Y].push_back(X);
    }
    cin >> W;

    fill(minTime, minTime + MAX, -1);
    cout << getMinTime(W) << "\n";
}

int main()
{
    cin.tie(0);
    cin >> T;
    while (T--) solution();
}