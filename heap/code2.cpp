// In this particular code we will do insert operations
// In insert operation we assume rest of the heap is already perfect
// so only value which is not at correct position is newly added value
// so we need to add it to proper place .. we will take it to upper place and place it there in O(logn)

// time complexity is O(logn) as we go through height of the tree

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
        vec.resize(n);
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
        int child = vec.size() - 1, prnt = parent(child);
        while (vec[child] > vec[prnt] && child > 0)
        {
            swap(vec[child], vec[prnt]);
            child = prnt;
            prnt = parent(child);
        }
    }
    void show_heap()
    {
        cout << "Showing heap: " << endl;
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Maxheap heap(0);
    heap.insert(5);
    heap.show_heap();

    heap.insert(10);
    heap.show_heap();

    heap.insert(-1);
    heap.show_heap();

    heap.insert(3);
    heap.show_heap();

    heap.insert(6);
    heap.show_heap();

    heap.insert(9);
    heap.show_heap();
    return 0;
}