// In this code we will see basic implementations of heap

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
};

int main()
{
    Maxheap heap(10);
    cout << "Parent of 3 is : " << heap.parent(3) << endl;
    cout << "Left child of 3 is: " << heap.left(3) << endl;
    return 0;
}