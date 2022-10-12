/*  problem No. 7568, 덩치
    code style: all code in main, using STL */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Dat {
    int x, y, rank;
};

int main()
{
    //input
    int N; cin >> N;
    vector<Dat> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].x >> v[i].y;
    }

    //process
    for (int i = 0; i < N; i++) {
        v[i].rank = 1;
        for (int j = 0; j < N; j++) {
            if (v[i].x < v[j].x && v[i].y < v[j].y) {
                v[i].rank++;
            }
        }
    }

    //output
    for (int i = 0; i < N; i++) {
        cout << v[i].rank << " ";
    }
}