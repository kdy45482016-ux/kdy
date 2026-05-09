#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> gates;
vector<bool> vis;
vector<int> ans;

void func(int pos){
    ans.push_back(pos);
    vis[pos] = true;

    for(auto gate : gates[pos]){
        if(vis[gate]) continue;
        func(gate);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    gates.resize(n + 1);
    vis.resize(n + 1, false);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        gates[a].push_back(b);
        gates[b].push_back(a);
    }
    for(auto &a : gates) sort(a.begin(), a.end());

    func(1);

    for(auto a : ans) cout << a << " ";
    cout << "\n";
}