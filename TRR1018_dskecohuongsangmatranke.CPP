#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;
    vector<vector<int>> ke(n+1);
    vector<int> deg_in(n+1,0);
    vector<int> deg_out(n+1,0);
    for(int i = 1; i <= n; i++){
        int k ; cin >> k;
        deg_out[i] = k;
        ke[i].resize(k);

        for(int j = 0; j < k; j++){
            cin >> ke[i][j];
        }
        
    }
    for (int i = 1; i <= n; i++) {
            for (int v : ke[i]) {
                deg_in[v]++;
            }
        }
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << deg_in[i] << " " << deg_out[i] << endl;
        }
    }
    if(t == 2){
        cout << n << endl;
        vector<vector<int>> a(n+1, vector<int> (n+1,0));
        for(int i = 1; i <= n ; i++){
            for(int x : ke[i]){
                if(x >= 1 && x <= n){
                    a[i][x]=1;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}