#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int c = 1; c <= n; c++)
    {
        for (long i = 0; i <= (n % 4 == 0 ? (n / 4) : (n / 4) + 1); i++)
        {
            if (c == (4 * i) + 1)
                cout << "*" << endl;
            if (c == (2 * i) + 2)
                cout << "   *" << endl;
            if (c == (3 * (i + 1)) + i)
                cout << "       *" << endl;
        }
    }
    return 0;
}