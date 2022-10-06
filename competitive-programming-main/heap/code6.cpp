// In this code we will see priority queues
// in c++ default priority queue is max heap

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;

// normal priority queue(max heap)
void solve1()
{
    priority_queue<int> pq;
    pq.push(5);
    pq.push(15);
    pq.push(20);
    pq.push(16);

    while (pq.empty() == false)
    { // 20 16 15 5
        cout << pq.top() << " ";
        pq.pop();
    }
}

// min heap
void solve2()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);
    pq.push(15);
    pq.push(20);
    pq.push(16);

    while (pq.empty() == false)
    {
        // 5 15 16 20
        cout << pq.top() << " ";
        pq.pop();
    }
}

struct person
{
    string name;
    int height, weight;

    person(int height1, int weight1, string name1)
    {
        name = name1;
        height = height1;
        weight = weight1;
    }
};

struct mycmp
{
    bool operator()(const person &a, const person &b)
    {
        return a.height < b.height;
    }
};

void solve3()
{
    priority_queue<person, vector<person>, mycmp> pq;
    pq.push({174, 58, "first"});
    pq.push({168, 45, "second"});
    pq.push({175, 68, "third"});

    while (pq.empty() == false)
    {
        person p1 = pq.top();
        cout << "Name is: " << p1.name << " Height is: " << p1.height << " Weight is: " << p1.weight << endl;
        pq.pop();
    }

    cout << "Second priority queue is(to check sorting in case of pairs): " << endl;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;

    // priority_queue<pair<int, int>> pq1;
    pq1.push({2, 3});
    pq1.push({-1, 5});
    pq1.push({0, 4});
    pq1.push({5, 6});

    while (pq1.empty() == false)
    {
        pair<int, int> curr = pq1.top();
        cout << curr.first << " " << curr.second << endl;
        pq1.pop();
    }
}

int main()
{
    // solve1();
    // solve2();
    solve3();
    return 0;
}