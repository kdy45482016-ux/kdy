#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<ll>> arr(n + 1);
    arr[0].resize(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        arr[i].resize(n + 1, 0);

        ll sum = 0;
        for(int j = 1; j <= n; j++) {
            ll temp;
            cin >> temp;

            sum += temp;
            arr[i][j] = sum;
        }
    }

    int q;
    cin >> q;

    vector<ll> ans(q);

    for(int i = 0; i < q; i++) {
        int sy, sx, ey, ex;
        cin >> sy >> sx >> ey >> ex;

        ll sum = 0;
        for(int j = sy; j <= ey; j++) {
            sum += arr[j][ex] - arr[j][sx - 1];
        }

        ans[i] = sum;
    }

    for(auto a : ans) cout << a << "\n";
}