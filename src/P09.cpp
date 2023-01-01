/**
 *    author:    hungt1
 *    created:   01-01-2023   12:37:03
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0)

int main()
{
    fastio;
    string s, t; cin >> s >> t;
    s = '#' + s; t = '#' + t;
    int n = s.length(), m = t.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (i == 0 && j == 0) dp[i][j] = true;
            else if (i == 0){
                if (j > 1 && t[j] == '*') dp[i][j] = (dp[i][j] || dp[i][j - 2]);
            }
            else if (j > 0){
                if (t[j] == s[i] || t[j] == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (t[j] == '*'){
                    dp[i][j] = (dp[i][j] || dp[i][j - 2]);
                    if (t[j - 1] == s[i] || t[j - 1] == '.'){
                        dp[i][j] = (dp[i][j] || dp[i - 1][j]);
                    }
                }
            }
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}