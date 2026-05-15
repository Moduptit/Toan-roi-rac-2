#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

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
    vector<bool> visited(n + 1, false);

    d[s] = 0;

    // Dijkstra
    for (int i = 1; i <= n; i++) {
        int u = -1;
        int minDist = INF;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && d[j] < minDist) {
                minDist = d[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && a[u][v] != INF) {
                if (d[v] > d[u] + a[u][v]) {
                    d[v] = d[u] + a[u][v];
                    trace[v] = u;
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

    for (int x : path) {
        cout << x << " ";
    }

    return 0;
}