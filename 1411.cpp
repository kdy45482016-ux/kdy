#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> dp(100000, 0);

int func(int n) {
    if(n < 2) return 1;

    if(dp[n - 2] == 0) dp[n - 2] = func(n - 2);
    if(dp[n - 1] == 0) dp[n - 1] = func(n - 1);

    return (dp[n - 2] * 2 + dp[n - 1]) % 20100529;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << func(n) << "\n";
}