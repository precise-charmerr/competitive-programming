#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

void solve()
{
    int total = 1000000 - 1, values = 10;
    // because we have to find (10^6) , so we will search for (10^6 - 1)
    vector<ll int> vec(values, 0);
    vec[0] = 1;
    for (int i = 1; i < vec.size(); i++)
    {
        vec[i] = vec[i - 1] * i;
    }

    reverse(vec.begin(), vec.end());
    vector<int> stval(values, 0);

    for (int i = 0; i < vec.size(); i++)
    {
        stval[i] = total / vec[i];
        total = total % vec[i];
    }

    vector<int> all;
    for (int i = 0; i < values; i++)
    {
        all.push_back(i);
    }

    string ans = "";

    for (int i = 0; i < stval.size(); i++)
    {
        int curr = stval[i], vtor = all[curr];
        ans += to_string(vtor);
        all.erase(all.begin() + curr);
    }

    cout << "ANSWER: " << ans << endl;

    return;
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
    printf("Time measured: %.4f seconds.", elapsed);
    return 0;
}