#include <bits/stdc++.h>
using namespace std;
int n, u, a[105][105], visited[105];

void dfs(int x){
    visited[x] = 1;
    for(int i = 1; i <= n; i ++){
        if(a[x][i] && !visited[i]) dfs(i);
    }
}
int main(){
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    int t; cin >> t;
    if(t == 1){
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j ++){
                cin >> a[i][j];
            }
        }

        int s = 0, odd = 0;
        for(int i = 1; i <= n; i++){
            int deg = 0;
            for(int j = 1; j <= n; j ++) deg += a[i][j];

            if(deg){
                s = 1;
                if(deg % 2) odd ++;
            }
        }

        dfs(s);
        for(int i = 1; i <= n; i ++){
            int deg = 0;
            for(int j = 1; j <= n; j++) deg += a[i][j];

            if(deg && !visited[i]){
                cout << 0;
                return 0;
            }
        }
        if(odd == 0) cout << 1;
        else if( odd == 2) cout << 2;
        else cout << 0;
    }
    if(t == 2){
        cin >> n >> u;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
            }
        }
        stack<int> st;
        vector<int> res;

        st.push(u);
        while(!st.empty()){
            int x = st.top(), y;
            for(y = 1; y <= n; y++){
                if(a[x][y]) break;
            }
            if(y <= n){
                st.push(y);
                a[x][y] = a[y][x] = 0;
            }
            else{
                res.push_back(x);
                st.pop();
            }
        }
        reverse(res.begin(), res.end());
        for(int x : res) cout << x << " ";
    }
    return 0;
}