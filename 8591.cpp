#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    arr.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = -10000000;

    for (int y1 = 0; y1 < n; y1++) {
        vector<int> col(m, 0);

        for (int y2 = y1; y2 < n; y2++) {
            for (int x = 0; x < m; x++) {
                col[x] += arr[y2][x];
            }

            int dp = col[0];
            ans = max(ans, dp);

            for (int x = 1; x < m; x++) {
                dp = max(col[x], dp + col[x]);
                ans = max(ans, dp);
            }
        }
    }

    cout << ans << '\n';
}