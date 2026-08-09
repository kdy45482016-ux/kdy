#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, k;
vector<ll> arr;
vector<ll> sum1;
vector<ll> sum2;

ll func(int l) {
    int r = l + k - 1;

    ll s1 = sum1[r] - sum1[l - 1];
    ll s2 = sum2[r] - sum2[l - 1];

    ll rs = 2LL * (s2 - (ll)l * s1) - ((ll)k - 1) * s1;

    return rs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> k;

    arr.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    sum1.resize(n + 1, 0);
    sum2.resize(n + 1, 0);

    ll temp1 = 0;
    ll temp2 = 0;

    for(int i = 1; i <= n; i++) {
        temp1 += arr[i - 1];
        temp2 += (ll)i * arr[i - 1];

        sum1[i] = temp1;
        sum2[i] = temp2;
    }

    ll ans = 9223372036854775807LL;

    for(int i = 1 ; i < n - k + 1; i++) {
        ans = min(ans, func(i));
    }

    cout << ans << "\n";
}