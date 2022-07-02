#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <limits.h>
using namespace std;

const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> sz(N);

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

signed main()
{
    for (int i = 0; i < N; i++)
    {
        make_set(i);
    }

    int n, m;
    cout << "Enter total edges & vertices : ";
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter Edge : ";
        cin >> u >> v;
        edges.push_back({u, v});
    }

    bool cycle = false;
    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        int x = find_set(u);
        int y = find_set(v);

        if (x == y)
        {
            cycle = true;
        }
        else
        {
            union_sets(u, v);
        }
    }
    if (cycle)
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is not present" << endl;
    }

    return 0;
}
