//problem No. 9184, 신나는 함수 실행
#include <iostream>
using namespace std;

int w(int a, int b, int c) {
    static int m[21][21][21];
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    if (m[a][b][c] == 0) {
        if (a < b && b < c)
            m[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        else 
            m[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }    
    return m[a][b][c];
}

int main()
{
    while (1) {
        //input
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 &&  c == -1) break;

        //process
        //output
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }

}