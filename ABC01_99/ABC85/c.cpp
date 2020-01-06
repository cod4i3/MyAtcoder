#include <iostream>
using namespace std;

int main()
{
    int N, Y;
    cin >> N >> Y;
    // i枚, j枚
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N - i; j++)
        {
            int a = 10000 * i;
            int b = 5000 * j;
            if (Y - a - b >= 0 && (Y - a - b) / 1000 == N - i - j)
            {
                cout << i << ' ' << j << ' ' << N - i - j << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}