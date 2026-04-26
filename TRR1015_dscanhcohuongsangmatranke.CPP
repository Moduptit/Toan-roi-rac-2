#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("DT.INP", "r", stdin);
  freopen("DT.OUT", "w", stdout);
  int t, n, m;
  cin >> t >> n >> m;
  vector<int> deg_in(n+1, 0);
  vector<int> deg_out(n+1,0);
  vector<vector<int>> a(n+1, vector<int>((n+1),0));
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
  
    deg_out[u]++;
    deg_in[v]++;
    
    a[u][v] = 1;
    
  }
  if(t == 1){
    for(int i = 1; i <= n;i++){
        cout << deg_in[i] << " " << deg_out[i] << endl;
    }
  }
  if(t == 2){
    cout << n << endl;
    for(int i = 1; i <= n; i++){
      for(int j = 1; j<= n; j++){
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}