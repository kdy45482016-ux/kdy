#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int n, m;
vector<set<int>> gates;
vector<bool> vis;
vector<int> ans;
stack<int> st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    gates.resize(n + 1);
    vis.resize(n + 1, false);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        gates[a].insert(b);
        gates[b].insert(a);
    }

    st.push(1);
    while(!st.empty()){
        int pos = st.top();
        st.pop();

        if(vis[pos]) continue;


        ans.push_back(pos);
        vis[pos] = true;

        vector<int> temp;
        for(auto gate : gates[pos]) temp.push_back(gate);
        for(int i = temp.size() - 1; i >= 0; i--) if(!vis[temp[i]]) st.push(temp[i]);
    }

    for(auto a : ans) cout << a << " ";
    cout << "\n";
}