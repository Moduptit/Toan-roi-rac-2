#include <bits/stdc++.h>
using namespace std;

int n;
int a[105][105];
bool visited[105];

void dfs(int u,int skip){
    visited[u] = true;
    
    for(int i = 1; i<= n; i++){
        if(i == skip) continue;
        if(a[u][i] == 1 && !visited[i]){
            dfs(i,skip);
        }
    }
}
int main(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= n; j++){
            cin >> a[i][j];
        }
    }

    vector<int> tru;

    for(int u = 1; u <= n; u++){
        memset(visited, false, sizeof(visited));

        int start = -1;
        for(int i = 1; i <= n; i++){
            if(i!=u){
                start = i;
                break;
            }
        }

        if (start == -1) continue;
        
        dfs(start,u);
        
        bool res = false;
        for(int x = 1; x <= n; x++){
            if(x != u && !visited[x]){
                res = true;
                break;
            }
        }
        if(res){
            tru.push_back(u);
        }
    }

    cout << tru.size() << endl;

    for(int v : tru) cout << v << " ";
    cout << endl;
    return 0;
}