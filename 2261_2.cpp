#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, s, e;
vector<string> codes;
queue<int> q;
vector<int> parent;
vector<int> vis;
vector<vector<int>> check;

bool is_ham(string a, string b) {
    int cnt = 0;
    for(int i = 0; i < a.length(); i++) if(a[i] != b[i] && cnt++) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    codes.resize(n + 1);
    parent.resize(n + 1, -1);
    vis.resize(n + 1, false);
    check.resize(n + 1);
    for(int i = 1; i <= n; i++) check[i].resize(n + 1, -1);

    for(int i = 1; i <= n; i++) cin >> codes[i];
    cin >> s >> e;

    vis[s] = true;
    q.push(s);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 1; i <= n; i++) {
            if(vis[i]) continue;
            if(check[cur][i] == -1) check[cur][i] = is_ham(codes[cur], codes[i]);
            if(!check[cur][i]) continue;

            vis[i] = true;
            parent[i] = cur;
            q.push(i);
        }
    }

    if(!vis[e]) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> ans;

    for(int i = e; i != -1; i = parent[i]) ans.push_back(i);

    for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
    cout << "\n";
}