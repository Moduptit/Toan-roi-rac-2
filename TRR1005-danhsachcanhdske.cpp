#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m; cin >> t >> n >> m;
    vector<pair<int,int>> edge;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        edge.push_back({u,v});
    }

    vector<int> deg(n+1,0);
        for(auto e : edge){
            int u = e.first; 
            int v = e.second;
            deg[u]++;
            deg[v]++;
        }
    
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << deg[i] << " ";
        }
    }
    if(t == 2){
        cout << n << endl;
        vector<vector<int>> ke(n+1);
        for(auto e : edge){
            int u = e.first;
            int v = e.second;

            ke[u].push_back(v);
            ke[v].push_back(u);
        }
        for(int i = 1; i <= n; i++){
            cout << ke[i].size() << " ";
            for(int x : ke[i]) cout << x << " ";
            cout << endl;
        }

    }
    return 0;
}