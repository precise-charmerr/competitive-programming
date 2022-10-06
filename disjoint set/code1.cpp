// disjoint set data structure basically is for finding groups
// so if we have have two groups with some number of people in it and two people of them become friends them that will be counted as
// one group

// data structures we can use here are graph(adjacency list or adjacency matrix)
// here if we want to do union then we have to add with all the members of second group and in worst case it can be O(n)
// coz we can connect with all n(all nodes) of that group
// here finding if two members are connected or not is O(1) so that is comparatively easy

// but here we use disjoint set data structure in which each group has a representative and when we add two group we make one as other's
// representative

// here adding is simple just add first to second and slowly we will optimise it
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

int find_parent(vector<int> &parent, int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    else
    {
        return find_parent(parent, parent[x]);
    }
}

void union_num(vector<int> &parent, int first, int second)
{
    int first_parent, second_parent;
    first_parent = find_parent(parent, first);
    second_parent = find_parent(parent, second);

    if (first_parent == second_parent)
    {
        return;
    }
    parent[first_parent] = second_parent;
}

void solve()
{
    int n = 8; // [0 - 7]
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int total; // number of operations we want to do
    cin>>total;
    while (total--)
    {
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            // union of two numbers

            cout << "Enter the numbers of which you have to make union: ";
            int first, second;
            cin >> first >> second;

            union_num(parent, first, second);
        }
        else
        {
            // find if two numbers are in same group or not

            cout << "Enter the numbers to find if they are in same group or not";
            int num1, num2;
            cin >> num1 >> num2;
            int first_parent, second_parent;
            first_parent = find_parent(parent, num1);
            second_parent = find_parent(parent, num2);

            if (first_parent == second_parent)
            {
                cout << "They are in same group!!" << endl;
            }
            else
            {
                cout << "They are in different group!!" << endl;
            }
        }

        cout << "check parent array: " << endl;
        for (int i = 0; i < parent.size(); i++)
        {
            cout << parent[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}

/*


0 1 2 3 4 5 6 7
union (2 4)

(0 1 3 5 6 7) (2 4)
are friends(7, 2)? --> NO
are friends(2, 4)? --> YES

union 2 7
(0 1 3 5 6) (2 4 7)
are friends(7, 2)? --> YES
are friends(2, 4)? --> YES

*/