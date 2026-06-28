#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, q;
vector<vector<ll>> arr;
vector<ll> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr.resize(n + 1);
    arr[0].resize(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        arr[i].resize(n + 1, 0);
        for(int j = 1; j <= n; j++) {
            ll temp;
            cin >> temp;
            arr[i][j] = temp + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }

    cin >> q;
    ans.resize(q);

    for(int i = 0; i < q; i++) {
        int sy, sx, ey, ex;
        cin >> sy >> sx >> ey >> ex;

        ll m = arr[sy - 1][sx - 1];

        ll a = arr[sy - 1][ex];
        ll b = arr[ey][sx - 1];

        ll e = arr[ey][ex];

        ans[i] = e - a - b + m;
    }

    for(auto a : ans) cout << a << "\n";
}