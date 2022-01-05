#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi v;
    v.pb(4);
    v.pb(5);
    cout << *(min_element(all(v)));
}