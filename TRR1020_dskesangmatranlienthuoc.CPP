#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n; cin >> t >> n;
    vector<int> deg_in(n+1,0);
    vector<int> deg_out(n+1,0);
    vector<vector<int>> ke(n+1);
    int res = 0; 
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        res += k;
        ke[i].resize(k);
        deg_out[i] = k;

        for(int j = 0; j < k; j++){
            cin >> ke[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int x : ke[i]){
            deg_in[x]++;
        }
    }

    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << deg_in[i] << " " << deg_out[i] << endl;
        }
    }
    if(t == 2){
        cout << n << " " << res << endl;
        vector<pair<int,int>> e;
        for(int i = 1; i <= n; i++){
            for(int v : ke[i]){
                e.push_back({i,v});
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < res; j++){
                if(i == e[j].first) cout << 1 << " ";
                else if(i == e[j].second) cout << -1 << " ";
                else cout << 0 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}