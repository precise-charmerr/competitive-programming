// In this code we will see code for heapify and extract min/max
// In heapify we assume values below a particular index are already perfectly heapified so we take this index and place its value
// at proper position

// In extract min/max the value is present at already first position we have to get this value and remove and the new values should again
// be a heap .. we we change first value with last and again call heapify for it because we know all other values are already heapified
// only first value is not in proper position

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

class Maxheap
{
    vector<int> vec;

public:
    Maxheap(int n)
    {
        // vec.resize(n);
        // for simplicity we are already making a heap here instead of pushing one by one

        vec = {10, 6, 9, 3, 5, -1};
    }
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
    void insert(int x)
    {
        vec.push_back(x);
        int child = vec.size() - 1;
        int prnt = parent(child);

        while (vec[child] > vec[prnt] && child > 0)
        {
            swap(vec[child], vec[prnt]);
            child = prnt;
            prnt = parent(child);
        }
    }

    void heapify(int i)
    {
        int lt = left(i), rt = right(i);
        int maxm = i;
        if (lt < vec.size() && vec[lt] > vec[maxm])
        {
            maxm = lt;
        }
        if (rt < vec.size() && vec[rt] > vec[maxm])
        {
            maxm = rt;
        }
        if (maxm != i)
        {
            swap(vec[maxm], vec[i]);
            heapify(maxm);
        }
    }

    int extract_max()
    {
        int ans = vec[0];
        swap(vec[0], vec[vec.size() - 1]);

        vec.pop_back();
        heapify(0);

        return ans;
    }
    void show_heap()
    {
        cout << "Showing heap: ";
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Maxheap heap(10);
    heap.show_heap();
    cout << "Maximum value is: " << heap.extract_max() << endl;
    heap.show_heap();
    return 0;
}