#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());

    int w;
    cin >> w;

    vector<int> memo(w + 1, INF);
    memo[0] = 0;

    for(int i = 1; i <= w; i++) {
        for(auto coin : coins) {
            if(coin > i) break;
            memo[i] = min(memo[i], memo[i - coin] + 1);
        }
    }

    if(memo[w] != INF) cout << memo[w] << "\n";
    else cout << "impossible\n";
}