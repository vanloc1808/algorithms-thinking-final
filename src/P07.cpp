/**
 *    author:    hungt1
 *    created:   30-12-2022   11:23:49
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    vector<int> a;
    string s;
    while (getline(cin, s, ',')){
        a.push_back(stoi(s));
    }

    int n = a.size();
    vector<int> prefix(n, 0), suffix(n, 0);
    for (int i = 0; i < n; i++){
        if (i == 0) prefix[i] = a[i];
        else prefix[i] = max(prefix[i - 1], a[i]);
    }

    for (int i = n - 1; i >= 0; i--){
        if (i == n - 1) suffix[i] = a[i];
        else suffix[i] = max(suffix[i + 1], a[i]);
    }

    long long total = 0;
    for (int i = 0; i < n; i++){
        int canReach = min(prefix[i], suffix[i]);
        total += canReach - a[i];
    }

    cout << total << '\n';
    return 0;
}