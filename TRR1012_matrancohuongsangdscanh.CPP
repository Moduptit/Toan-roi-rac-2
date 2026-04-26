#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;
    vector<vector<int>> a(n+1,vector<int>((n+1),0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    if(t == 1){
        for(int i = 1; i <= n; i++){
            int deg_in = 0, deg_out = 0;
            for(int j = 1; j <= n; j++){
                deg_in += a[j][i];
                deg_out += a[i][j];
            }
            cout << deg_in << " " << deg_out << endl;
        }
        
    }
    if(t == 2){
        vector<pair<int,int>> edge;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(a[i][j] == 1) edge.push_back({i,j});
            }
        }
        cout << n << " " << edge.size() << endl;
        for(auto e : edge){
            cout << e.first << " " <<  e.second << endl;
        }
    }
    return 0;
}