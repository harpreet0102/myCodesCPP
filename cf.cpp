#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all v.begin(), v.end()

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a = 1, b, c;
        cin >> n;
        if (n % 2 == 0)
        {
            b = (n - 1) / 2;
            c = n - 1 - b;
        }
        else
        {
            b = (n - 1) / 2;
            c = b;
            if (b % 2 == 0)
            {
                b = b - 1;
                c = c + 1;
            }
            else if (b % 2 != 0 && b != 1)
            {
                b = b - 2;
                c = c + 2;
            }
        }
        cout << b << " " << c << " " << a << endl;
    }
}