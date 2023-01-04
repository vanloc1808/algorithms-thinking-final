/**
 *    author:    hungt1
 *    created:   30-12-2022   11:06:49
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int MOD = 1e9 + 7;
const int BASE = 257;
const int N = 1e6 + 1;

int _hash[N], p[N];

int getHash(int l, int r){
    return (_hash[r] - 1ll * _hash[l - 1] * p[r - l + 1] % MOD + MOD) % MOD;
}

int main()
{
    fastio;
    string s, t; cin >> s >> t;
    
    int n = s.length(); 
    int m = t.length();

    if (m > n) return 0;

    p[0] = 1;
    for (int i = 0; i < n; i++){
        _hash[i + 1] = (1ll * _hash[i] * BASE + s[i]) % MOD;
        p[i + 1] = (1ll * p[i] * BASE) % MOD;
    }

    int tHash = 0;
    for (int i = 0; i < m; i++){
        tHash = (1ll * tHash * BASE + t[i]) % MOD;
    }

    for (int i = 1; i <= n - m + 1; i++){
        if (getHash(i, i + m - 1) == tHash){
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}