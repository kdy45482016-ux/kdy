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
    vector<int> fgt_arr(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        int word = arr[i];
        int fgt = 0;
        
        for(int j = i; j <= n; j++) {
            dif_arr[j] += word;
            fgt_arr[j] += fgt;

            if(word == 0) break;

            fgt = min(word, m);
            word -= fgt;
        }
    }

    // for(auto a : dif_arr) cout << a << " "; cout << "\n";
    // for(auto a : fgt_arr) cout << a << " "; cout << "\n";

    for(int i = 0; i < q; i++) {
        int code, t;
        cin >> code >> t;

        switch(code) {
            case 1 : cout << dif_arr[t] << "\n"; break;
            case 2 : cout << fgt_arr[t] << "\n"; break;
        }
    }
}