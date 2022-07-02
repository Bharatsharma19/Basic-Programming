#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main()
{
    int n, m;
    cout << "Enter edges & vertices : ";
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "Enter : ";
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cout << "Enter Source : ";
    cin >> src;

    vector<int> dist(n, INF);

    dist[src] = 0;

    for (int iter = 0; iter < (n - 1); iter++)
    {
        // bool change = false;
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            /*
            if (dist[v] > w + dist[u])
            {
                change = true;
            }
            */

            dist[v] = min(dist[v], w + dist[u]);
        }
    }

    for (auto i : dist)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
