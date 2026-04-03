#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);


    int t; cin >> t;
    int n, m; cin >> n >> m;
    vector <pair<int,int>> edge;
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edge.push_back({u,v});
    }

    if( t == 1){
        vector<int> deg(n+1,0);
        for(auto e : edge){
            int u = e.first; 
            int v = e.second;
            deg[u] ++;
            deg[v] ++;
        }
        for(int i = 1; i <= n; i++){
            cout << deg[i] << " ";
        }
    }
    if(t == 2){
        cout << n << endl;
        vector<vector<int>> a(n+1,vector<int>(n+1,0));
        for(auto  e : edge){
            int u = e.first; 
            int v = e.second;

            a[u][v] = 1;
            a[v][u] = 1;
        }
        for(int i = 1 ; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;

        }
    }

    return 0;
}