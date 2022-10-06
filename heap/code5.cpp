// Heap sort

// In this code we wil be doing heap sort of any vector
// firstly we will form heap of the vector then get maximum step by step and them swapping them with last elemnent
// and will maintain heap property of remaining elements
// here we will make max heap

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

int left(int i)
{
    return (2 * i) + 1;
}

int right(int i)
{
    return (2 * i) + 2;
}

int parent(int i)
{
    return (i - 1) / 2;
}

void heapify(vector<int> &vec, int i, int n)
{
    int lt = left(i), rt = right(i);
    int maxm = i;
    if (lt < n && vec[lt] > vec[maxm])
    {
        maxm = lt;
    }
    if (rt < n && vec[rt] > vec[maxm])
    {
        maxm = rt;
    }
    if (maxm != i)
    {
        swap(vec[maxm], vec[i]);
        heapify(vec, maxm, n);
    }
}

void build_heap(vector<int> &vec)
{
    int last_parent = parent(vec.size() - 1);
    for (int i = last_parent; i >= 0; i--)
    {
        heapify(vec, i, vec.size());
    }
}

void heap_sort(vector<int> &vec)
{
    build_heap(vec);
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        swap(vec[0], vec[i]);
        heapify(vec, 0, i);
    }

    cout << "Final Sorted Heap: " << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec = {0, 2, 3, -1, 9, 10, 4, 6};
    heap_sort(vec);
    return 0;
}