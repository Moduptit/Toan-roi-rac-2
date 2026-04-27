#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m; cin >> t >> n >> m;
    vector<int> deg_in(n+1,0);
    vector<int> deg_out(n+1, 0);
    vector<pair<int,int>> e;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        deg_in[v]++;
        deg_out[u]++;
        e.push_back({u,v});
    }

    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << deg_in[i] << " " << deg_out[i] << endl;
        }
    }
    if(t == 2){
        cout << n << " " << m << endl;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < m ; j++){
                if(i == e[j].first) cout << 1 << " ";
                else if( i == e[j].second) cout << -1 << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}