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

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

bool compare(pii p1, pii p2)
{
    double v1 = (double)p1.ff / p2.ss;
    double v2 = (double)p2.ff / p2.ss;

    return (v1 > v2);
}

signed main()
{
    int n;
    cout << "Enter number of items : ";
    cin >> n;

    vii a(n);

    rep(i, 0, n)
    {
        cout << "Enter Weight : ";
        cin >> a[i].ff >> a[i].ss;
    }

    int w;
    cout << "Enter weight of sack : ";
    cin >> w;

    sort(a.begin(), a.end(), compare);

    int ans = 0;

    rep(i, 0, n)
    {
        if (w >= a[i].ss)
        {
            ans += a[i].ff;
            w -= a[i].ss;
            continue;
        }

        double vw = (double)a[i].ff / a[i].ss;
        ans += vw * w;
        w = 0;
        break;
    }

    cout << ans << endl;

    return 0;
}
