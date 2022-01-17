#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct point
{
    int x, y;
    point(int _x, int _y) : x(_x), y(_y) {}
    point operator+(const point& p)
    {
        return point(x + p.x, y + p.y);
    }
};

class Map
{
public:
    int N, M;
    vector<vector<int>> map;
    vector<point> list_void;
    vector<point> list_virus;

    Map(int n, int m) : N(n), M(m) {}

    void get_data()
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
        list_void.clear();
        list_virus.clear();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (map[i][j] == 0)
                    list_void.push_back({ i, j });
                else if (map[i][j] == 2)
                    list_virus.push_back({ i, j });
    }

    void set_wall(const point& p)
    {
        map[p.x][p.y] = 1;
    }

    void spread_virus()
    {
        point deltas[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        auto viruses = list_virus;

        while (!viruses.empty())
        {
            for (auto& dt : deltas)
            {
                point newVirus = viruses.front() + dt;
                if (!isValid(newVirus)) continue;
                if (map[newVirus.x][newVirus.y] == 0)
                {
                    map[newVirus.x][newVirus.y] = 2;
                    viruses.push_back(newVirus);
                }
            }
            viruses.erase(viruses.begin());
        }
    }

    bool isValid(const point& p)
    {
        return 0 <= p.x && p.x < N && 0 <= p.y && p.y < M;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    Map origin(N, M);
    origin.get_data();
    origin.analyze();

    int maxSize = 0;
    auto size = origin.list_void.size();
    for (int i = 0; i < size - 2; i++)
        for (int j = i + 1; j < size - 1; j++)
            for (int k = j + 1; k < size; k++)
            {
                Map simul(origin);
                simul.set_wall(simul.list_void[i]);
                simul.set_wall(simul.list_void[j]);
                simul.set_wall(simul.list_void[k]);
                simul.spread_virus();
                simul.analyze();
                maxSize = max(maxSize, (int)simul.list_void.size());
            }
    
    cout << maxSize;

    return 0;
}