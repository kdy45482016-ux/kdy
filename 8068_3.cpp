#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<ll> arr(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<ll> dif_cnt(n + 1, 0);
    vector<ll> dif_sum(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        int end = i + (arr[i] + m - 1) / m;
        ll val = arr[i] + (ll)i * m;

        dif_cnt[i] += 1;
        dif_sum[i] += val;

        if(end <= n) {
            dif_cnt[end] -= 1;
            dif_sum[end] -= val;
        }
    }

    vector<ll> memory(n + 1, 0);
    vector<ll> forget(n + 1, 0);

    ll cnt = 0;
    ll sum = 0;

    for(int i = 1; i <= n; i++) {
        cnt += dif_cnt[i];
        sum += dif_sum[i];

        memory[i] = sum - cnt * i * m;

        forget[i] = memory[i - 1] + arr[i] - memory[i];
    }

    for(int i = 0; i < q; i++) {
        int code, t;
        cin >> code >> t;
        
        cout << (code == 1 ? memory[t] : forget[t]) << "\n";
    }
}