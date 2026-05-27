#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool is_ham(string a, string b) {
    int cnt = 0;
    for(int i = 0; i < a.length(); i++) if(a[i] != b[i] && cnt++ > 0) return false;
    return true;
}

int n, k;
int s, e;
vector<string> codes;
queue<vector<int>> q;

vector<vector<int>> check; // [a][b] : a <-> b, -1 : 확인안함, 0 : 아님, 1 : 맞음

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    codes.resize(n + 1);
    check.resize(n + 1);

    for(int i = 1; i <= n; i++) {
        check[i].resize(n + 1, -1);
        cin >> codes[i];
    }
    
    cin >> s >> e;

    q.push({s});

    while(!q.empty()) {
        vector<vector<int>> arr;

        while(!q.empty()) {
            arr.push_back(q.front());
            q.pop();
        }

        for(auto cur : arr) {
            vector<int> vis(n + 1, false);
            for(auto e : cur) vis[e] = true;

            for(int i = 1; i <= n; i++) {
                if(vis[i]) continue;
                if(check[cur.back()][i] == -1) check[cur.back()][i] = is_ham(codes[cur.back()], codes[i]);
                if(!check[cur.back()][i]) continue;
                vector<int> nxt = cur;
                nxt.push_back(i);
                q.push(nxt);

                if(i != e) continue;
                for(auto e : nxt) cout << e << " ";
                cout << "\n";
                return 0;
            }
        }
    }

    cout << -1 << "\n";
}