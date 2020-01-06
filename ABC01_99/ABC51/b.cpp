#include <iostream>
using namespace std;

int main()
{
    int k, s;
    int x, y, z;
    int cnt = 0;
    cin >> k >> s;
    for (x = 0; x <= k; x++)
    {
        for (y = 0; y <= k; y++)
        {
            if (0 <= s - x - y && s - x - y <= k)
                cnt++;
        }
    }

    cout << cnt << endl;
}