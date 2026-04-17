#include <bits/stdc++.h>
using namespace std;

int n;
bool visited[105];
vector<int> tp;
int a[105][105];

void dfs(int u){
    visited[u] = true;
    tp.push_back(u);
    for(int i = 1; i<= n; i++){
        if(a[u][i] == 1 && !visited[i]){
            dfs(i);
        }
    }
}
int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    cin >> n;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    memset(visited, false, sizeof(visited));

    vector<vector<int>> res;
    for(int i = 1; i<= n; i++){
        if(!visited[i]){
            tp.clear();
            dfs(i);
            sort(tp.begin(), tp.end());
            res.push_back(tp);
        }
    }

    cout << res.size() << endl;
    for(auto& v : res){
        for(int x : v){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}