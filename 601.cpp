#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "ma";
    string t = "Bharat Sharma";

    int S = s.size(), T = t.size();

    for (int i = 0; i < (T - S + 1); i++)
    {
        if (t.substr(i, S) == s)
        {
            cout << "Found at index " << i << "\n";
        }
    }

    // Time Complexity = O(ST)

    return 0;
}
