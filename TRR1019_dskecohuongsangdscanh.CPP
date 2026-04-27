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
        deg_out[i] = k;
        ke[i].resize(k);
        for(int j = 0; j < k; j++){
            cin >> ke[i][j];
        }
    }
    for(int i = 1; i<= n; i++){
        for(int v : ke[i]) deg_in[v]++;
    }
    if(t== 1){
        for(int i = 1; i <= n; i++){
            cout << deg_in[i] << " " << deg_out[i] << endl;
        }
    }
    if(t == 2){
        cout << n << " " << res << endl;
        vector<pair<int,int>> e;
        for(int i = 1; i <= n; i++){
            for(int x : ke[i]){
                e.push_back({i,x});
            }
        }
        for(auto o : e){
            cout << o.first <<" " << o.second << endl;
        }
    }
    
    return 0;
}