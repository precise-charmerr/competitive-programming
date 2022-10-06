// Decrease key, Delete and Build heaps

// First of all, Build heaps .. in building heaps we take the last value which is someone's parent and start heapify function from it
// we do it cause in heapify .. we are sure that below that particular index everything is heapified so we take minimum possible parent
// and go in reverse order

// In decease key, we decease value at a particular index .. here we normally decrease value and go up or doen depending on type of heap
// if the heap is max heap then we have to go down because place for decreased key is at lower position
// ad if heap is min heap then we have to go up because new lower value should be placed upwards

// Delete any key .. can be done through two ways ..
// 1. replace it with last value and call heapify for that
// 2. make the value INT_MIN / INT_MAX depending on type of heap and call extact_min / extract_max accordingly ...

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
        // for simplicity we directly inserts vector here
        vec = {0, 2, 3, -1, 9, 10, 4, 6};
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
        cout << "Showing heap is: ";
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
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

    void build_heap()
    {
        int first_parent = parent(vec.size() - 1);
        for (int i = first_parent; i >= 0; i--)
        {
            heapify(i);
        }
    }
    void decrease_key(int index, int value)
    {
        vec[index] = value;
        heapify(index);
    }

    void delete_key(int index)
    {
        // first way is making index value as INT_MAX and then removing it
        // vec[index] = INT_MAX;
        // int child = index, prnt = parent(child);
        // while (vec[child] > vec[prnt] && child > 0)
        // {
        //     swap(vec[child], vec[prnt]);
        //     child = prnt;
        //     prnt = parent(child);
        // }
        // int ans = extract_max();

        // second way is swapping element with last element and calling heapify for it

        swap(vec[index], vec[vec.size() - 1]);
        vec.pop_back();
        heapify(index);
    }
};

int main()
{
    Maxheap heap(10);        // 0 2 3 -1 9 10 4 6
    heap.build_heap();       // 10 9 4 6 2 3 0 -1
    heap.decrease_key(1, 5); // 10 6 4 5 2 3 0 -1
    heap.delete_key(1);      // 10 5 4 -1 2 3 0
    return 0;
}