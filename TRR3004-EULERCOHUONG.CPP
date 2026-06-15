#include<bits/stdc++.h>
using namespace std;

int t, n, u;

set<int> ke[1005];
int in[1005], out[1005];
bool visited[1005];

vector<vector<int>> a;

void dfs(int u){
    visited[u] = true;
    for(int x : ke[u]){
        if(!visited[x]) dfs(x);
    }
}

// liên thông (bỏ đỉnh cô lập)
bool check(){
    memset(visited, false, sizeof(visited));

    int start = -1;
    for(int i = 1; i <= n; i++){
        if(out[i] + in[i] > 0){
            start = i;
            break;
        }
    }

    if(start == -1) return true;

    dfs(start);

    for(int i = 1; i <= n; i++){
        if((in[i] + out[i] > 0) && !visited[i])
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

            // chỉ xóa 1 chiều (quan trọng)
            ke[x].erase(y);
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

    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));

    if(t == 1){
        cin >> n;

        a.assign(n+1, vector<int>(n+1, 0));

        for(int i = 1; i <= n; i++)
            ke[i].clear();

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];

                if(a[i][j]){
                    out[i]++;
                    in[j]++;

                    ke[i].insert(j);
                }
            }
        }

        if(!check()){
            cout << 0;
            return 0;
        }

        int start = 0, end = 0;

        for(int i = 1; i <= n; i++){
            if(out[i] - in[i] == 1) start++;
            else if(in[i] - out[i] == 1) end++;
            else if(in[i] != out[i]){
                cout << 0;
                return 0;
            }
        }

        if(start == 0 && end == 0)
            cout << 1; // Euler cycle
        else if(start == 1 && end == 1)
            cout << 2; // Euler path (nửa Euler)
        else
            cout << 0;
    }
    else{
        cin >> n >> u;

        a.assign(n+1, vector<int>(n+1, 0));

        for(int i = 1; i <= n; i++)
            ke[i].clear();

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> a[i][j];

                if(a[i][j]){
                    out[i]++;
                    in[j]++;

                    ke[i].insert(j);
                }
            }
        }

        euler(u);
    }

    return 0;
}