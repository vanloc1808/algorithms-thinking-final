/**
 *    author:    hungt1
 *    created:   01-01-2023   11:50:39
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    vector<long long> p;
    long long x;
    while (cin >> x){
        p.push_back(x);
    }
    long long y = p.back(); p.pop_back();

    long long ans = 0;
    int n = p.size();
    vector<long long> fact(n + 1, 1);
    for (int i = 1; i <= n; i++){
        fact[i] = fact[i - 1] * i;
    }

    vector<bool> used(n + 1, 0);
    for (int i = 0; i < n; i++){
        int cnt = 0;
        for (int x = 1; x < p[i]; x++){
            if (!used[x]) cnt++;
        }
        ans += cnt * fact[n - i - 1];
        used[p[i]] = true;
    }
    cout << ans + 1 << '\n';

    y--;
    vector<int> res;
    used.assign(n + 1, 0);
    for (int i = 0; i < n; i++){
        int cnt = 0;
        for (int x = 1; x <= n; x++){
            if (used[x]) continue;
            if (cnt == y / fact[n - i - 1]){
                res.push_back(x);
                used[x] = true;
                break;
            }
            cnt++;
        }
        y %= fact[n - i - 1];
    }   
    for (int x : res) cout << x << ' '; cout << '\n';
    return 0;
}