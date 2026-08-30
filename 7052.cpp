#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int n, m;
ll a, b;
vector<vector<ll>> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> a >> b;

    if(a > b) swap(a, b);

    arr.resize(n, vector<ll>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    ll mi = 5000000000000;

    for(int top = 0; top < n; top++) {
        vector<ll> col(m, 0);

        for(int btm = top; btm < n; btm++) {
            for(int x = 0; x < m; x++) {
                col[x] += arr[btm][x];
            }

            vector<ll> pfx(m + 1, 0);
            for(int i = 1; i <= m; i++) {
                pfx[i] = pfx[i - 1] + col[i - 1];
            }

            int l = 1;
            for(int r = 1; r <= m; r++) {
                while(l <= r) {
                    ll sum = pfx[r] - pfx[l - 1];
                    ll dist = min(abs(a-sum), abs(b-sum));

                    mi = min(mi, dist);

                    if(sum < a) break;
                    if(sum > b) l++;
                    else {
                        cout << b - a << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << b - a + mi * 2 << "\n";
}