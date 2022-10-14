﻿/*  problem No. 2630, 색종이 만들기
    code style: all code in main, using STL */
#include <iostream>
#include <vector>
using namespace std;

int getColor(vector<vector<int>>& p, int len, int x, int y)
{
    for (int dy = 0; dy < len; dy++) {
        for (int dx = 0; dx < len; dx++) {
            if (p[y][x] != p[y + dy][x + dx]) {
                return -1;
            }
        }
    }
    return p[y][x];
}

void countColor(int& w, int& b, vector<vector<int>>& p, int len, int x, int y)
{
    switch (getColor(p, len, x, y)) {
    case 0:
        w++;
        break;
    case 1:
        b++;
        break;
    case -1:
        len /= 2;
        countColor(w, b, p, len, x, y);
        countColor(w, b, p, len, x + len, y);
        countColor(w, b, p, len, x, y + len);
        countColor(w, b, p, len, x + len, y + len);
        break;
    }
}

int main()
{
    //input
    int N; cin >> N;
    vector<vector<int>> p(N);
    for (int i = 0; i < N; i++) {
        p[i].resize(N);
        for (int j = 0; j < N; j++) {
            cin >> p[i][j];
        }
    }

    //process
    int w = 0, b = 0;
    countColor(w, b, p, N, 0, 0);

    //output
    cout << w << endl << b;
}