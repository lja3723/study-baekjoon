#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
using point = pair<int, int>;

class Map
{
public:
    int N, M;
    vector<vector<int>> map;
    vector<point> list_void;
    vector<point> list_virus;

    Map(int n, int m) : N(n), M(m) {}

    explicit operator int()
    {
        return 0;
    }

    void getData()
    {
        map.clear();
        for (int i = 0; i < N; i++)
        {
            map.push_back(vector<int>());
            for (int j = 0; j < M; j++)
            {
                int k;
                cin >> k;
                map[i].push_back(k);
            }
        }
    }

    void analyze()
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (map[i][j] == 0)
                    list_void.push_back({ i, j });
                else if (map[i][j] == 2)
                    list_virus.push_back({ i, j });
    }

    void setWall(point p)
    {

    }

    void spread_virus()
    {

    }
};


int main()
{
    int N, M;
    cin >> N >> M;
    Map origin(N, M), calc(N, M);
    origin.getData();   

    return 0;
}