#include <bits/stdc++.h>
using namespace std;
int n, u, v;
bool visited[1005];
int parent[105];
int a[1005][1005];
bool found = false;

void dfs(int start){
    visited[start] = true;
    if(start == v){
        found = true;
        return;
    }
    for(int i = 1; i <= n; i++){
        if(a[start][i] == 1 && !visited[i]){
            parent[i] = start;
            dfs(i);

            if(found) return;
        }
    }
}

int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    int t; cin >> t;
    cin >> n >> u >> v;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j ++){
            cin >> a[i][j];
        }
    }
    if(t == 1){
        int cnt = 0;
        for(int k = 1; k <= n; k++){
            if(a[u][k] == 1 && a[k][v] == 1){
                ++cnt;
            }
        }
        cout << cnt << endl;
    }
    if(t == 2){
        memset(parent, -1, sizeof(parent));
        dfs(u);
        if(!found) cout << 0;
        else{
            vector<int> path;
            int cur = v;
            while(cur != -1){
                path.push_back(cur);
                cur = parent[cur];
            }
            reverse(path.begin(), path.end());
            for(int x : path) cout << x << " ";
        }
    }

    return 0;
}