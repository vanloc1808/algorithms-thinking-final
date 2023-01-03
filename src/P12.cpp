#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    int a = -1, b = -1;
    set<int> s;

    // check if n is a sum of two squares
    for (int i = 0; i * i <= n; i++) {
        s.insert(i * i);

        if (s.count(n - i * i)) {
            a = i;
            b = sqrt(n - i * i);
            break;
        }
    }

    if (a == -1 && b == -1) {
        cout << "Impossible\n";
    } else {
        int x = min(a, b);
        int y = max(a, b);

        cout << x << " " << x << "\n";
        cout << 2 * x << " " << x + y << "\n";
        cout << 2 * x + y << " " << y << "\n";
        cout << x + y << " " << 0 << "\n";
    }
}

int main() {
    int n;
    cin >> n;

    solve(n);
}