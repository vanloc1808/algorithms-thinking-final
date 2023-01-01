/**
 *    author:    hungt1
 *    created:   01-01-2023   10:57:24
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const long long INF = 1e18;

struct Point{
    int x, y;
    Point() {}
    Point(int x, int y): x(x), y(y) {}
};

long long area(vector<Point> a){
    long long ans = 0;
    int n = a.size();
    a.push_back(a[0]);
    for (int i = 0; i < n; i++){
        ans += 1ll * (a[i].x - a[i + 1].x) * (a[i].y + a[i + 1].y);
    }
    return ans;
}

long long area(Point a, Point b, Point c){
    return abs((b.x - a.x) * (b.y + a.y) + (c.x - b.x) * (c.y + b.y) + (a.x - c.x) * (a.y + c.y));
}

int main()
{
    fastio;
    int n; cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y;
    }

    long long total = area(a);
    
    int j = 1; 
    int first = 0, second = 1;
    long long cur = 0, diff = INF;
    for (int i = 0; i < n; i++){
        while (cur < total - cur){
            if (abs(total - 2 * cur) < diff){
                diff = abs(total - 2 * cur);
                first = i;
                second = j;
            }
            cur += area(a[i], a[j], a[(j + 1) % n]);
            j = (j + 1) % n;
        }
        if (abs(total - 2 * cur) < diff){
            diff = abs(total - 2 * cur);
            first = i;
            second = j;
        }
        cur -= area(a[i], a[(i + 1) % n], a[j]);
    } 
    cout << first + 1 << ' ' << second + 1 << '\n';
    return 0;
}