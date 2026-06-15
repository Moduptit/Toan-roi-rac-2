#include<bits/stdc++.h>
using namespace std;

int t, n, u;

set<int> ke[1005];
int deg[1005];
bool visited[1005];

vector<vector<int>> a;

void dfs(int u){
    visited[u] = true;
    for(int x : ke[u]){
        if(!visited[x]) dfs(x);
    }
}
bool check(){
    memset(visited, false, sizeof(visited));
    int start = -1;
    for(int i = 1; i <= n; i++){
        if(deg[i] > 0){
            start = i;
            break;
        }
    }
    if(start == -1) return true;
    dfs(start);
    for(int i = 1; i <= n; i++){
        if(deg[i] > 0 && !visited[i])
            return false;
    }
    return true;
}

void euler(int u){
    stack<int> st;
    vector<int> CE;
    st.push(u);
    while(!st.empty()){
        int x = st.top();
        if(!ke[x].empty()){
            int y = *ke[x].begin();
            st.push(y);
            ke[x].erase(y);
            ke[y].erase(x);
        }
        else{
            st.pop();
            CE.push_back(x);
        }
    }
    reverse(CE.begin(), CE.end());
    for(int x : CE) cout << x << " ";
}

int main(){
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    cin >> t;
    memset(deg, 0, sizeof(deg));

    if(t == 1){
        cin >> n;
        a.assign(n+1, vector<int>(n+1));
        for(int i = 1; i <= n; i++)
            ke[i].clear();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
                if(a[i][j]){
                    deg[i]++;
                    if(i < j){
                        ke[i].insert(j);
                        ke[j].insert(i);
                    }
                }
            }
        }
        if(!check()){
            cout << 0;
            return 0;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(deg[i] % 2) cnt++;
        }
        if(cnt == 0) cout << 1;
        else if(cnt == 2) cout << 2;
        else cout << 0;
    }
    else{
        cin >> n >> u;
        a.assign(n+1, vector<int>(n+1));
        for(int i = 1; i <= n; i++)
            ke[i].clear();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];
                if(a[i][j]){
                    if(i < j){
                        ke[i].insert(j);
                        ke[j].insert(i);
                    }
                }
            }
        }
        euler(u);
    }

    return 0;
}