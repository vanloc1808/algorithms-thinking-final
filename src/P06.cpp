/**
 *    author:    hungt1
 *    created:   30-12-2022   11:19:32
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define Tuple array<int, 3>
int main()
{
    fastio;
    int k; cin >> k;
    vector<vector<int>> a(k, vector<int>());
    cin.ignore();
    for (int i = 0; i < k; i++){
        string s; getline(cin, s);
        stringstream ss(s);
        int x;
        while (ss >> x) a[i].push_back(x);
    }
    priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;
    for (int i = 0; i < k; i++){
        pq.push({a[i][0], i, 0});
    }

    vector<int> ans;
    while (!pq.empty()){
        auto [val, i, j] = pq.top(); pq.pop();
        ans.push_back(val);
        if (j + 1 < a[i].size()){
            pq.push({a[i][j + 1], i, j + 1});
        }
    }

    for (int x : ans) cout << x << ' '; cout << '\n';
    return 0;
}