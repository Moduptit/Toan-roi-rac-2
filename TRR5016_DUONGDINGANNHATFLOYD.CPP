#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> d(n + 1, vector<int>(n + 1));
    vector<vector<int>> trace(n + 1, vector<int>(n + 1));
    // Nhập ma trận trọng số
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
            if (i != j && d[i][j] != INF) {
                trace[i][j] = j;
            }
            else {
                trace[i][j] = -1;
            }
        }
    }

    // Floyd
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] != INF && d[k][j] != INF) {
                    if (d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                        trace[i][j] = trace[i][k];

                    }
                }
            }
        }
    }

    int u = -1, v = -1;
    int maxDist = -1;

    // Tìm cặp đỉnh có đường đi ngắn nhất lớn nhất
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && d[i][j] != INF) {
                if (d[i][j] > maxDist) {
                    maxDist = d[i][j];
                    u = i;
                    v = j;
                }
            }
        }
    }

    // Không tồn tại cặp đỉnh
    if (u == -1) {
        cout << 0;
        return 0;
    }
    // In kết quả
    cout << u << " " << v << " " << d[u][v] << endl;
    // Truy vết đường đi
    vector<int> path;
    int cur = u;
    while (cur != v) {
        path.push_back(cur);
        cur = trace[cur][v];
    }

    path.push_back(v);
    // In đường đi
    for (int x : path) {
        cout << x << " ";
    }

    return 0;
}