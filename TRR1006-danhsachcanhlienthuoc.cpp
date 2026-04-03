#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m; cin >> t >> n >> m;
    vector<pair<int,int>> edge(m+1);
    for(int i = 1; i <= m; i++){
        cin >> edge[i].first >> edge[i].second;
    }
    if(t == 1){
        vector<int> deg(n+1);
        for(auto e : edge){
            int u = e. first;
            int v = e.second;

            deg[u]++;
            deg[v]++;
        }
        for(int i = 1; i <= n; i++){
            cout << deg[i] << " ";
        }
    }
    if(t == 2){
        cout << n << " " << m << endl;
        vector<vector<int>> a(n+1, vector<int>(m+1,0));
        for(int j = 1; j <= m; j++){
            int u = edge[j].first;
            int v = edge[j].second;

            a[u][j] = 1;
            a[v][j] = 1;
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }

    }
    return 0;
}