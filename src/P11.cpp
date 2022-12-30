/**
 *    author:    hungt1
 *    created:   30-12-2022   20:48:23
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    int k, n, m; cin >> k >> n >> m;
    int t = k - n - m;
    vector<int> a(k), b(k);
    for (int i = 0; i < k; i++){
        cin >> a[i] >> b[i];
    }
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(t + 1, 0)));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            for (int l = 0; l <= t; l++){
                int idx = i + j + l; // 0-based
                if (i + 1 <= n) dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l] + a[idx]);
                if (j + 1 <= m) dp[i][j + 1][l] = max(dp[i][j + 1][l], dp[i][j][l] + b[idx]);
                if (l + 1 <= t) dp[i][j][l + 1] = max(dp[i][j][l + 1], dp[i][j][l]);
            }
        }
    }
    cout << dp[n][m][t] << '\n';
    return 0;
}