#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;
string final = "";

void func(int k, int64_t n, vector<int64_t> &vec, vector<int> &fac)
{
    // cout << "func: K: " << k << " n: " << n << endl;
    if (k == 0)
    {
        return;
    }
    if (k == 1)
    {
        char curr = 'a';
        final += curr;
        return;
    }
    int start = 0, end = k - 1;
    int64_t csum = 0, prev = 0;
    while (start < k)
    {
        csum += vec[start] * vec[end];
        if (csum >= n)
        {
            // ck-1, k = csum;
            char curr = 'a' + start;
            final += curr;
            // cout << "curr: " << curr << " start: " << start << endl;
            fac[final.size() + start] += start + 1;
            func(start, n - prev, vec, fac);
            func(end, n - prev, vec, fac);
            return;
        }
        prev = csum;
        start++;
        end--;
    }
}

void solve()
{
    int64_t n;
    int k;
    cin >> n >> k;
    vector<int64_t> vec(k + 1, 0);
    vector<int> fac(k, 0);
    vec[0] = vec[1] = 1;
    int start = 0, end = 0;
    for (int i = 2; i <= k; i++)
    {
        start = 0, end = i - 1;
        while (start < i)
        {
            vec[i] += vec[start] * vec[end];
            start++;
            end--;
        }
    }
    func(k, n, vec, fac);

    // cout << "FINAL: " << final << endl;

    // cout << "FACTOR: " << endl;
    // for (int i = 0; i < fac.size(); i++)
    // {
    //     cout << fac[i] << " ";
    // }
    // cout << endl;

    string ans = final;
    for (int i = k - 1; i >= 0; i--)
    {
        for (int j = i; j < k; j++)
        {
            ans[j] = ans[j] + fac[i];
        }
    }

    cout << "answer: " << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin.exceptions(cin.failbit);

    solve();
    return 0;
}