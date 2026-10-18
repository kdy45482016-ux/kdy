#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(41, 0);

int func(int n) {
    if(n < 2) return 1;
    if(dp[n] != 0) return dp[n];

    return dp[n] = func(n-2) + func(n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr;

    int last = 0;
    for(int i = 0; i < m; i++) {
        int fixed;
        cin >> fixed;
        arr.push_back(fixed - last - 1);
        last = fixed;
    }
    arr.push_back(n - last);

    int ans = 1;
    for(auto len : arr) {
        ans *= func(len);
    }

    cout << ans << "\n";
}