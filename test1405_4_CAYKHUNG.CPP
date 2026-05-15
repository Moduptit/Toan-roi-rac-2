#include <bits/stdc++.h>
using namespace std;

int t, n, s, a[105][105], vis[105];
vector<pair<int,int>> e;

void dfs(int u){
    vis[u] = 1;

    for(int v = 1; v <= n; v++)
        if(a[u][v] && !vis[v]){
            e.push_back({u, v});
            dfs(v);
        }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s] = 1;

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int v = 1; v <= n; v++)
            if(a[u][v] && !vis[v]){
                vis[v] = 1;
                e.push_back({u, v});
                q.push(v);
            }
    }
}

int main(){
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> t >> n >> s;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    if(t == 1) dfs(s);
    else bfs(s);

    if(e.size() != n - 1){
        cout << 0;
        return 0;
    }

    cout << n - 1 << '\n';

    for(auto x : e)
        cout << x.first << ' ' << x.second << '\n';
}