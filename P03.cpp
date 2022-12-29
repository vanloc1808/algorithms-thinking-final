#include <bits/stdc++.h>

using namespace std;

pair<int, int> solve(vector<pair<long long, int>> a, int m, vector<pair<long long, int>> b, int n) {
    // sort a and b in ascending order
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int aidx = 0, bidx = 0;

    // if a and b contain all positive numbers
    if (a[0].first >= 0 && b[0].first >= 0) {
        return make_pair(1, 1);
    }

    // if a and b contain all negative numbers
    if (a[m - 1].first < 0 && b[n - 1].first < 0) {
        return make_pair(m, n);
    }

    // if ONLY ONE of a and b contains both positive and negative number
    if (a[0].first >= 0 && b[0].first < 0 && b[n - 1].first >= 0) {
        bidx = 0;
        
        long long minValue = abs(a[0].first + b[bidx].first);

        for (int j = 1; j < m; j++) {
            if (abs(a[j].first + b[bidx].first) < minValue) {
                minValue = abs(a[j].first + b[bidx].first);
                aidx = j;
            }
        }

        return make_pair(a[aidx].second, b[bidx].second);
    }
    if (b[0].first >= 0 && a[0].first < 0 && a[m - 1].first >= 0) {
        aidx = 0;

        long long minValue = abs(a[aidx].first + b[0].first);

        for (int j = 1; j < n; j++) {
            if (abs(a[aidx].first + b[j].first) < minValue) {
                minValue = abs(a[aidx].first + b[j].first);
                bidx = j;
            }
        }

        return make_pair(a[aidx].second, b[bidx].second);
    }

    // if BOTH a and b contain both positive and negative numbers
    aidx = 0;
    bidx = n - 1;
    long long minValue = LONG_LONG_MAX;

    // 2 pointers approach
    while (aidx < m && bidx >= 0) {
        long long temp = a[aidx].first + b[bidx].first;
        long long tempAbs = abs(temp);
        
        if (tempAbs < minValue) {
            minValue = tempAbs;
            aidx = aidx;
            bidx = bidx;
        }

        // if temp < 0, need to increase temp to reduce the absolute value
        // else need to decrease temp to reduce the absolute value
        if (temp < 0) {
            aidx++;
        } else {
            bidx--;
        }
    }

    return make_pair(a[aidx].second, b[bidx].second);
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<pair<long long, int>> a(m);
    vector<pair<long long, int>> b(n);

    for (int i = 0; i < m; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i + 1;
    }

    pair<int, int> result = solve(a, m, b, n);
    cout << result.first << " " << result.second << endl;

    return 0;
}