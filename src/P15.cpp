#include <bits/stdc++.h>

using namespace std;

// find the union area of 2 circles
double solve(int x1, int y1, int x2, int y2, int r) {
    // find d = O1O2
    double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // find the area of a circle
    double area = M_PI * pow(r, 2);

    if (d >= 2 * r) {
        return 2 * area;
    }

    double O1C = d / 2;

    double angleAO1B = acos(O1C / r) * 2;

    double areaTriangleAO1B = pow(r, 2) * sin(angleAO1B) / 2;

    double sectorAO1B = (angleAO1B / (2 * M_PI)) * area;

    double areaAO1B = sectorAO1B - areaTriangleAO1B;

    double areaOverlapping = 2 * areaAO1B;

    return area + area - areaOverlapping;
}

int main() {
    int x1, y1, x2, y2, r;
    cin >> x1 >> y1 >> x2 >> y2 >> r;

    double ans = solve(x1, y1, x2, y2, r);
    cout << fixed << setprecision(3) << ans << "\n";

    return 0;
}