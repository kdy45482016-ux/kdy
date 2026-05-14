#include <iostream>
#include <vector>

using namespace std;

int n, m, x;
vector<vector<int>> up, down;
vector<int> vis;

int func(int pos, vector<vector<int>>& arr) { // pos보다 높은(낮은) 등수 개수 + 1 반환
    vis[pos] = true;

    int cnt = 0;

    for(auto a : arr[pos]){
        if(vis[a]) continue;
        cnt += func(a, arr);
    }

    return cnt + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;

    down.resize(n + 1);
    up.resize(n + 1);
    vis.resize(n + 1, false);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        up[b].push_back(a); // b보다 a가 높음
        down[a].push_back(b); // a보다 b가 낮음
    }

    int up_num = func(x, up) - 1; // 높은 등수 개수
    int down_num = func(x, down) - 1; // 낮은 등수 개수

    cout << up_num + 1 << " ";
    cout << n - down_num << "\n";
}