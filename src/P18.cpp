/**
 *    author:    hungt1
 *    created:   01-01-2023   11:21:01
**/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0)

int bfs(string src, string dst, int n){
    unordered_map<string, int> dist;
    queue<string> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty()){
        string u = q.front(); q.pop();
        if (u == dst){
            return dist[u];
        }
        for (int i = 1; i < n; i++){
            string v = u;
            reverse(v.begin(), v.begin() + i + 1);
            if (dist.find(v) == dist.end()){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main()
{
    fastio;
    int n; cin >> n;
    string src = "";
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        src += (char)('0' + x);
    }

    string dst = "";
    for (int i = 0; i < n; i++){
        dst += (char)('0' + i + 1);
    }

    cout << bfs(src, dst, n) << '\n';
    return 0;
}