/**
 *    author:    hungt1
 *    created:   01-01-2023   12:28:16
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0)

// tourist template
template <typename T, typename func = function<T(const T, const T)>>
struct SparseTable {
    func calc;
    int n;
    vector<vector<T>> ans;

    SparseTable() {}

    SparseTable(const vector<T>& a, const func& f) : n(a.size()), calc(f) {
        int last = trunc(log2(n)) + 1;
        ans.resize(n);
        for (int i = 0; i < n; i++){
            ans[i].resize(last);
        }
        for (int i = 0; i < n; i++){
            ans[i][0] = a[i];
        }
        for (int j = 1; j < last; j++){
            for (int i = 0; i <= n - (1 << j); i++){
                ans[i][j] = calc(ans[i][j - 1], ans[i + (1 << (j - 1))][j - 1]);    
            }
        }
    }

    T query(int l, int r){
        assert(0 <= l && l <= r && r < n);
        int k = trunc(log2(r - l + 1));
        return calc(ans[l][k], ans[r - (1 << k) + 1][k]);
    }
};

int main()
{
    fastio;
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }    

    SparseTable<int> st(a, [](int x, int y){
        return __gcd(x, y);
    });

    int ans = 0;
    for (int i = 0; i < n - k + 1; i++){
        int cur = st.query(i, i + k - 1);
        if (cur > ans) ans = cur;
    }
    cout << ans << '\n';
    return 0;
}