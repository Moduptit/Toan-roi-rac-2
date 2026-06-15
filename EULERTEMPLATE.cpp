#include<bits/stdc++.h>
using namespace std;
int n, m;
set<int> ke[1001];
int deg[1001];
void nhap (){
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int x, y; cin >> x >> y;
        ke[x].insert(y);
        ke[y].insert(x);
        deg[x]++;
        deg[y]++;
    }
}
// chu trinh euler
void euler(int v){
    stack<int> st;
    vector<int> CE;
    st.push(v);
    while(!st.empty()){
        int x = st.top();
        if(ke[x].size() != 0){
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
    for(auto x : CE) cout << x << ' ';
}

int main(){

    return 0;
}