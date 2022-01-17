#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, maxCnt;
int map[8][8];
int tmp[8][8];
vector<pair<int, int>> emptyList;

void combination(){
    int len = emptyList.size();
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            for(int k = j + 1; k < len; k++){
                init(i, j, k);
                bfs();
            }
        }
    }
}

void init(int fst, int snd, int trd) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            tmp[i][j] = map[i][j];

    tmp[emptyList[fst].first][emptyList[fst].second] =
        tmp[emptyList[snd].first][emptyList[snd].second] =
        tmp[emptyList[trd].first][emptyList[trd].second] = 1;
}

void bfs() {
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (tmp[i][j] == 2)
                q.push({ i, j });

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if (ny >= N  ny < 0  nx >= M || nx < 0)    continue;
            if (tmp[ny][nx] == 0) {
                tmp[ny][nx] = 2;
                q.push({ ny, nx });
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (tmp[i][j] == 0)
                cnt++;
    maxCnt = max(cnt, maxCnt);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 0)
                emptyList.push_back({i, j});
        }
    }

    combination();
    cout << maxCnt;
}