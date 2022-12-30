/**
 *    author:    hungt1
 *    created:   30-12-2022   10:58:02
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    int n; cin >> n;
    vector<int> isPrime(2 * n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 2 * n; i++){
        if (isPrime[i]){
            for (int j = i * i; j <= 2 * n; j += i){
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= 2 * n; i++){
        if (isPrime[i]){
            primes.push_back(i);
        }
    }

    vector<int> g(n + 1, 0);
    for (int i = 0; i < primes.size(); i++){
        for (int j = i; j < primes.size(); j++){
            int cur = primes[i] + primes[j];
            if (cur % 2 == 0 && cur <= 2 * n){
                g[cur / 2]++;
            }
        }
    }

    int ans = 0;
    for (int i = 2; i <= n; i++){
        ans += g[i];
    }

    cout << ans << '\n';
    return 0;
}