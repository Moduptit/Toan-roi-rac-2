#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

int main() {
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    int n, s, t;
    cin >> n >> s >> t;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> d(n + 1, INF);
    vector<int> trace(n + 1, -1);

    d[s] = 0;

    // Bellman-Ford
    for (int k = 1; k <= n - 1; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (a[u][v] != INF && d[u] != INF) {
                    if (d[v] > d[u] + a[u][v]) {
                        d[v] = d[u] + a[u][v];
                        trace[v] = u;
                    }
                }
            }
        }
    }
    // Kiểm tra chu trình âm
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (a[u][v] != INF && d[u] != INF) {
                if (d[v] > d[u] + a[u][v]) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    // Không có đường đi
    if (d[t] == INF) {
        cout << 0;
        return 0;
    }
    // In độ dài đường đi ngắn nhất
    cout << d[t] << endl;

    // Truy vết đường đi
    vector<int> path;

    int cur = t;
    while (cur != -1) {
        path.push_back(cur);
        cur = trace[cur];
    }
    reverse(path.begin(), path.end());

    // In đường đi
    for (int x : path) {
        cout << x << " ";
    }

    return 0;
}