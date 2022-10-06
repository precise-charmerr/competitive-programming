// In the previous code we simply added first with another
// so in worst case we time complexity can be O(n)
// like example is 0 ,1, 2, 3, 4
// union(3, 4) , union(2, 3), union(1, 2), union(0, 1)

// this thing will take O(n) so here we will do it union with rank
// basically we will check which tree is smaller size and which one is larger and we will make smaller one as larger one's child
// and in case if both have same height, then we can add any one with any other .. and increase rank of one which will be the parent
//  of the other... this technique will do find in O(logn) coz tree height will never increase linearly

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

int find(vector<int> &parent, int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return find(parent, parent[x]);
}

void union_num(vector<int> &parent, vector<int> &rank, int first, int second)
{
    int pfirst = find(parent, first);
    int psecond = find(parent, second);
    if (pfirst == psecond)
    {
        return;
    }

    cout << "rank of first: " << rank[pfirst] << " rank of second: " << rank[second] << endl;
    if (rank[pfirst] < rank[psecond])
    {
        parent[pfirst] = psecond;
    }
    else if (rank[pfirst] > rank[psecond])
    {
        parent[psecond] = pfirst;
    }
    else
    {
        parent[pfirst] = psecond;
        rank[psecond]++;
    }
}

void solve()
{
    int n = 8; // 0 - 7
    // here we will maintain rank and parent array both
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int total; // total number of operations we want to do
    cin >> total;
    while (total--)
    {
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            // union
            int num1, num2;
            cin >> num1 >> num2;
            union_num(parent, rank, num1, num2);
        }
        else
        {
            // find
            int num1, num2;
            cin >> num1 >> num2;
            int first_parent = find(parent, num1), second_parent = find(parent, num2);
            if (first_parent == second_parent)
            {
                cout << "They are in same group" << endl;
            }
            else
            {
                cout << "They are not in same group" << endl;
            }
        }

        cout << "Check Parent Array: " << endl;
        for (int i = 0; i < parent.size(); i++)
        {
            cout << parent[i] << " ";
        }
        cout << endl;
        cout << "Check Rank Array: " << endl;
        for (int i = 0; i < rank.size(); i++)
        {
            cout << rank[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}