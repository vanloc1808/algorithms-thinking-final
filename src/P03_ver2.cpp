/**
 *    author:    hungt1
 *    created:   30-12-2022   20:07:37
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define li pair<long long, int>

const long long INF = 1e18;

int main()
{
    fastio;
    int m, n; cin >> m >> n;
    vector<li> a(m), b(n);
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        a[i] = {x, i};
    }
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        b[i] = {x, i};
    }

    sort(a.begin(), a.end(), greater<li>()); 
    sort(b.begin(), b.end());

    int aidx = 0, bidx = 0;
    long long minDiff = INF;
    int j = 0;
    for (int i = 0; i < m; i++){
        while (j < n && b[j].first < -a[i].first){
            j++;
        }
        if (j < n && abs(a[i].first + b[j].first) < minDiff){ // lower_bound
            minDiff = abs(a[i].first + b[j].first);
            aidx = a[i].second;
            bidx = b[j].second;
        }
        if (j > 0 && abs(a[i].first + b[j - 1].first) < minDiff){ // lower_bound - 1
            minDiff = abs(a[i].first + b[j - 1].first);
            aidx = a[i].second;
            bidx = b[j - 1].second;
        }
    }

    cout << aidx + 1 << ' ' << bidx + 1 << '\n';
    return 0;
}