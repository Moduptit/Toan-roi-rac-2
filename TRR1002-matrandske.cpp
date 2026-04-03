#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n; cin >> t >> n;
    int a [105][105];

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
    if(t == 2){
        for(int i = 1; i <= n; i++){
            int cnt = 0;
            for(int j = 1; j <= n; j++){
                if (a[i][j] == 1) ++cnt;
            }
            cout << cnt << " ";

            for(int j = 1; j<=n; j++){
                if(a[i][j] == 1){
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }


    return 0;
}