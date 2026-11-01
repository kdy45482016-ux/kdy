#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int n, w;
vector<int> coin;
vector<int> memo;
vector<int> vis;

int func(int m) {  // m 채우는 동전 최소 개수
    if(vis[m]) return memo[m];
    vis[m] = true;
    if(memo[m] != INF) return memo[m];
    
    for(auto c : coin) {
        if(c > m) continue;
        memo[m] = min(memo[m], func(m - c) + 1);
    }

    return memo[m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    coin.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    sort(coin.begin(), coin.end());

    cin >> w;

    memo.resize(w + 1, INF);
    vis.resize(w + 1, false);

    memo[0] = 0;

    int rs = func(w);
    if(rs != INF) cout << rs << "\n";
    else cout << "impossible\n";
}