#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;
const ll int maxi = 1e18 + 8;

void solve()
{
    int64_t k = 60, x = 7;
    int64_t total = pow(2, k + 1), sec = total - x;

    cout << "solve --> total: " << total << " sec+x: " << sec + x << endl;
}

void solve2()
{
    int64_t k = 60, x = 7;
    int64_t total = pow(2, k + 1), sec = pow(2, k + 1) - x;

    cout << "solve2 --> total: " << total << " sec+x: " << (sec + x) << endl;
}

int main()
{
    solve();
    solve2();
    return 0;
}