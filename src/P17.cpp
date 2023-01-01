/**
 *    author:    hungt1
 *    created:   30-12-2022   20:59:06
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    int n; cin >> n;
    for (int mask = 1; mask < (1 << 9); mask++){
        vector<int> a;
        for (int i = 0; i < 9; i++){
            a.push_back((mask >> i) & 1);
        }
        reverse(a.begin(), a.end());
        int cur = 0;
        for (int x : a){
            cur = cur * 10 + x;
        }
        if (cur % n == 0){
            cout << cur << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}