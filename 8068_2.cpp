#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> arr(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> dif_arr(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        int word = arr[i];
        dif_arr[i] += word;
        int idx = i, max_idx = min(n, i + word / m);
        while(++idx <= max_idx) {
            dif_arr[idx] -= m;
        }
        dif_arr[idx] -= word % m;
    }

    vector<int> sum_arr(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        sum_arr[i] = sum_arr[i - 1] + dif_arr[i];
    }

    for(auto a : dif_arr) cout << a << " "; cout << "\n";
    for(auto a : sum_arr) cout << a << " "; cout << "\n";

    for(int i = 0; i < q; i++) {
        int code, t;
        cin >> code >> t;

        switch(code) {
            case 1 : cout << 0 << "\n"; break;
            case 2 : cout << 0 << "\n"; break;
        }
    }
}