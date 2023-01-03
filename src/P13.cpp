#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x;
    int y;
};

pair<int, int> solve(int n, vector<pair<Point, int>> points) {
    pair<int, int> ans;

    // find the bottom left point
    int bottomLeftIdx = 0;
    for (int i = 0; i < n; i++) {
        if (points[i].first.x < points[bottomLeftIdx].first.x) {
            bottomLeftIdx = points[i].second - 1;
        } else if (points[i].first.x == points[bottomLeftIdx].first.x) {
            if (points[i].first.y < points[bottomLeftIdx].first.y) {
                bottomLeftIdx = points[i].second - 1;
            }
        }
    }

    // find the slope of each points to the bottom left point
    vector<pair<double, int>> slopes;
    for (int i = 0; i < n; i++) {
        if (i == bottomLeftIdx) {
            continue;
        }

        int dx = points[i].first.x - points[bottomLeftIdx].first.x;
        if (dx == 0) {
            slopes.push_back({INT_MAX, points[i].second});
        } else {
            int dy = points[i].first.y - points[bottomLeftIdx].first.y;
            slopes.push_back({(double)dy / dx, points[i].second});
        }
    }

    // sort the slope in ascending order (counter-clockwise)
    sort(slopes.begin(), slopes.end());

    // find the median of slope
    int medianIdx = slopes.size() / 2;

    int idx = slopes[medianIdx].second;

    ans.first = min(bottomLeftIdx + 1, idx);
    ans.second = max(bottomLeftIdx + 1, idx);

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<pair<Point, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first.x >> points[i].first.y;
        points[i].second = i + 1;
    }

    pair<int, int> ans = solve(n, points);

    cout << ans.first << " " << ans.second << "\n";
}