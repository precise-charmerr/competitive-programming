#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void solve()
{
    ll int x = 1000000, ans = -1;
    ll int maxm = -1;
    for (int i = 1; i < x; i++)
    {
        ll int curr_ans = 1, val = i;
        // finding count of chain for each number from 1 to 10^6
        while (val != 1)
        {
            curr_ans++;
            if (val % 2 == 0)
            {
                val = val / 2;
            }
            else
            {
                val = (3 * val) + 1;
            }
        }
        if (curr_ans >= maxm)
        {
            ans = i;
            maxm = curr_ans;
        }
    }
    cout << ans << endl;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin.exceptions(cin.failbit);

    clock_t start = clock();

    solve();

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    printf("Time measured: %.3f seconds.\n", elapsed);

    return 0;
}