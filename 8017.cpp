#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const vector<int> move_val = {-1, 1};

ll load_size;
int n, out_len;
queue<pair<ll, int>> check;
map<ll, int> vis;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> load_size >> n >> out_len;

    for(int i = 0; i < n; i++) {
        ll input;
        cin >> input;
        check.push({input, 0});
        vis[input] = true;
    }

    while(!check.empty()) {
        ll pos = check.front().first;
        int cnt = check.front().second;
        check.pop();
        cout << cnt << "\n";
        if(--out_len < 1) break;

        for(int m : move_val) {
            ll new_pos = pos + (ll)m;
            if(new_pos < 0 || new_pos > load_size) continue;
            if(vis.find(new_pos) != vis.end()) continue;

            vis[new_pos] = true;
            check.push({new_pos, cnt + 1});
        }
    }
}