#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
const int inf = 1e9 + 7;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;

vector<int> seg_tree, seg_tree2;

ll int find(int current_node, int node_left, int node_right, int range_left, int range_right)
{
    if (node_right < range_left || node_left > range_right)
    {
        return 0;
    }
    if (node_left >= range_left && node_right <= range_right)
    {
        return seg_tree[current_node];
    }
    int left_child_right = (node_left + node_right) / 2;
    return find(2 * current_node, node_left, left_child_right, range_left, range_right) +
           find((2 * current_node) + 1, left_child_right + 1, node_right, range_left, range_right);
}

void update(int index, int n, int tree_type)
{
    if (tree_type == 1)
    {
        seg_tree[n + index] = 0;
        int parent = (n + index) / 2;
        for (int i = parent; i >= 1; i /= 2)
        {
            seg_tree[i] = seg_tree[2 * i] + seg_tree[2 * i + 1];
        }
        return;
    }
    seg_tree2[n + index] = 0;
    int parent = (n + index) / 2;
    for (int i = parent; i >= 1; i /= 2)
    {
        seg_tree2[i] = seg_tree2[2 * i] + seg_tree2[2 * i + 1];
    }
    return;
}

int find_by_ord(int current_node, int node_left, int node_right, int k)
{
    // cout << "CURRENT NODE: " << current_node << " NODE LEFT: " << node_left << " NODE_RIGHT: " << node_right << endl;
    if (node_left == node_right)
    {
        return current_node;
    }
    int left_child_right = (node_left + node_right) / 2;
    int left_value = seg_tree2[2 * current_node], right_value = seg_tree2[2 * current_node + 1];
    if (k <= left_value)
    {
        return find_by_ord(2 * current_node, node_left, left_child_right, k);
    }
    return find_by_ord(2 * current_node + 1, left_child_right + 1, node_right, k - left_value);
}

vector<int> find_code(vector<int> &vec)
{
    int n = vec.size(), os = n;
    while (__builtin_popcount(n) != 1)
    {
        n++;
    }
    seg_tree.resize(2 * n);
    for (int i = 0; i < os; i++)
    {
        seg_tree[n + i] = 1;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        seg_tree[i] = seg_tree[2 * i] + seg_tree[(2 * i) + 1];
    }
    seg_tree2 = seg_tree;
    vector<int> ans;

    for (int i = 0; i < vec.size(); i++)
    {
        int curr = vec[i];
        int vless = find(1, 0, n - 1, 0, curr - 1);
        ans.push_back(vless);
        update(curr, n, 1);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    vector<int> first = find_code(p);
    vector<int> second = find_code(q);
    for (int i = 0; i < first.size(); i++)
    {
        first[i] = first[i] + second[i];
    }
    reverse(first.begin(), first.end());

    for (int i = 0; i < first.size(); i++)
    {
        int minm_amnt = i + 1;
        if (first[i] >= minm_amnt)
        {
            first[i] -= minm_amnt;
            if (i < first.size() - 1)
            {
                first[i + 1] += 1;
            }
        }
    }
    reverse(first.begin(), first.end());
    vector<int> final_ans;

    // Code using ordered_set

    ordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(i);
    }

    for (int i = 0; i < n; i++)
    {
        int curr = first[i];
        int x = *(s.find_by_order(curr));
        final_ans.push_back(x);
        s.erase(x);
    }
    for (int i = 0; i < final_ans.size(); i++)
    {
        cout << final_ans[i] << " ";
    }

    // code using seg tree and writing our functions which were previously written in ordered set

    final_ans.clear();
    while (__builtin_popcount(n) != 1)
    {
        n++;
    }

    for (int i = 0; i < first.size(); i++)
    {
        int num = first[i], value = find_by_ord(1, 0, n - 1, num + 1) - n;
        final_ans.push_back(value);
        update(value, n, 2);
    }
    for (int i = 0; i < final_ans.size(); i++)
    {
        cout << final_ans[i] << " ";
    }
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