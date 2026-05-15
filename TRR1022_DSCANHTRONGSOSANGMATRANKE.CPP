#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m;
    cin >> t >> n >> m;
    vector<int> deg_in(n+1);
    vector<int> deg_out(n+1);
    vector<vector<int>> e;
    vector<vector<int>> a(n + 1, vector<int>(n+1, INF));
    for(int i = 0; i < m;  i++){
        int u, v, w;
        cin >> u >> v >> w;
        deg_in[v]++;
        deg_out[u]++;
        a[u][v] = w;
        e.push_back({u, v, w});
    }
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << deg_in[i] << " " << deg_out[i] << endl;
        }
    }
    if(t == 2){
        cout << n << endl;
        for(int i = 1; i <= n; i++ ){
            for(int j = 1; j <= n; j ++){
                if(i == j) a[i][j] = 0;
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}