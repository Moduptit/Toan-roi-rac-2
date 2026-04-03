#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n; cin >> t >> n;
    int a[105][105];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    if(t == 1){
        for(int i = 1; i <= n; i++){
            int deg = 0;
            for(int j = 1; j <= n; j++){
                deg += a[i][j];
            }
            cout << deg << " ";
        }
    }
    else if( t == 2){
        vector<pair<int,int>> e;

        for(int i = 1; i <= n; i ++){
            for(int j = i + 1; j <= n; j++){
                if (a[i][j]) e.push_back({i,j});
            }
        }
        int m = e. size();
        cout << n << " " << m << endl;

        for(int i = 1; i <= n; i++){
            for(int j = 0 ; j < m; j++){
                cout <<  (i == e[j].first || i == e[j].second) << " ";
            }
            cout  << endl;
        }
    }

    return 0;
}