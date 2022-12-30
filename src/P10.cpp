/**
 *    author:    hungt1
 *    created:   30-12-2022   20:42:48
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int solve(vector<vector<int>> &a, int n, int m, int val){
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] != val) dp[i][j] = 0;
            else if (i == 0 || j == 0) dp[i][j] = 1;
            else {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}


int main()
{
    fastio;
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    cout << max(solve(a, n, m, 0), solve(a, n, m, 1)) << '\n';
    return 0;
}