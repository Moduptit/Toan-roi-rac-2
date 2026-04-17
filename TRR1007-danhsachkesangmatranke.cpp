#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n; cin >> t >> n;

    vector<vector<int>> ke(n + 1);
    vector<int> deg(n+1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        deg[i] = k;
        ke[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> ke[i][j];
        }
    }
    if (t == 1) {
        
        for (int i = 1; i <= n; i++) {
            cout << deg[i] << " ";
        }
    }

    if (t == 2) {
        

        vector<vector<int>> a(n + 1, vector<int>((n + 1), 0));
        for (int i = 1; i <= n; i++) {
            for (int v : ke[i]) {
                if (v >= 1 && v <= n) {
                    a[i][v] = 1;
                    a[v][i] = 1;
                }
            }
        }

        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}