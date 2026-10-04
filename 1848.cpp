#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(41, 0);

int fibo(int n) {
    if(n <= 1) return 1;

    if(dp[n - 2] == 0) dp[n - 2] = fibo(n - 2);
    if(dp[n - 1] == 0) dp[n - 1] = fibo(n - 1);

    return dp[n - 2] + dp[n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n;
    cin >> m;
    
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
    for(auto a : arr) {
        ans *= fibo(a);
    }

    cout << ans << "\n";
}