#include <bits/stdc++.h>
using namespace std;

const int INF = 10000;

int main(){
    //nhap
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;
    vector<vector<int>> a(n+1, vector<int>((n+1), INF));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    if(t == 1){
        for(int i = 1; i <= n; i++){
            int deg_in = 0, deg_out = 0;
            for(int j = 1; j <= n; j++){
                // duong cheo duoc luu la 0;
                if(i != j && a[i][j] != INF){
                    deg_out++;
                }
                if(i != j && a[j][i] != INF){
                    deg_in++;
                }
            }
            cout << deg_in << " " << deg_out << endl;
        }
    }
    if(t == 2){
        vector<vector<int>> edge;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i != j && a[i][j] != INF){
                    edge.push_back({i, j, a[i][j]});
                }
            }
        }
        sort(edge.begin(),edge.end());

        cout << n << " " << edge.size() << endl;
        for(auto e : edge){
            cout << e[0] << " " << e[1] << " " << e[2] << endl;
        }
    }
    return 0;
}