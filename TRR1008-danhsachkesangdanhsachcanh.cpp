#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n; cin >> t >> n;
    int res;
    vector<vector<int>> ke(n + 1);
    vector<int> deg(n+1);
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        res+=k;
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
    if(t == 2){
        int m = res/2;
        cout << n << " " << m << endl;
        set<pair<int,int>> edge;
        for(int i = 1; i <= n; i++){
            for(int x : ke[i]){
                int u = min(i, x);
                int v = max(i,x);
                edge.insert({u,v});
            }
        }
        for(auto e : edge){
            cout << e.first << " " << e.second << endl;
        }
    }
    return 0;
}