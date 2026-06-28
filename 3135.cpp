#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, q;
vector<ll> arr;
vector<ll> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr.resize(n + 1, 0);

    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        sum += (ll)temp;
        arr[i] = sum;
    }

    cin >> q;
    ans.resize(q);

    for(int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        ans[i] = arr[e] - arr[s - 1];
    }

    for(auto a : ans) cout << a << "\n";
}