/**
 *    created: $CURRENT_DATE.$CURRENT_MONTH.$CURRENT_YEAR $CURRENT_HOUR:$CURRENT_MINUTE:$CURRENT_SECOND",
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
void use_ordered_set()
{
    ll int n;
    cin >> n;
    vector<ll int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ordered_set<pair<ll int, ll int>> s, t;
    ll int ans = 0;
    for (int i = 0; i < n; i++)
    {
        s.insert({arr[i], i});
        t.insert({-arr[i], i});
        ll int low = s.order_of_key((pair<int, int>){arr[i], -1});
        ll int high = t.order_of_key((pair<int, int>){-arr[i], -1});
        ans += min(low, high);
    }
    cout << ans << endl;
}

void input_output()
{
    int64_t n;
    scanf("%" SCNd64, &n);
    printf("%I64d", n);
    // for ceil -> x/y+1-(x%y==0)
}

ll int printNcR(int n, int r)
{
    long long p = 1, k = 1;
    if (n - r < r)
    {
        r = n - r;
    }
    while (r)
    {
        p *= n;
        k *= r;
        long long m = __gcd(p, k);
        p /= m;
        k /= m;
        n--;
        r--;
    }
    return p;
}
void precision_values()
{
    // changing int to double
    int number = 10;
    double dou_val = 1.0 * number;
    // finding values upto some precision
    cout << fixed << setprecision(12) << sqrt(dou_val) << endl;
}
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin.exceptions(cin.failbit);
    // clock_t start = clock();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // clock_t end = clock();
    // double elapsed = double(end - start) / CLOCKS_PER_SEC;
    // printf("Time measured: %.4f seconds.", elapsed);
    return 0;
}
