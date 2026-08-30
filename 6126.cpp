#include <iostream>
#include <vector>

#define MAX_SIZE 1000001

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(MAX_SIZE, 0);

    int max_len = 1;

    for(int i = 0; i < n; i++) {
        int s, e, c;
        cin >> s >> e >> c;

        arr[s] += c;
        arr[e + 1] -= c;
        
        max_len = max(max_len, e + 1);
    }

    vector<int> pfx(MAX_SIZE, 0);

    for(int i = 1; i < max_len; i++) {
        pfx[i] = pfx[i - 1] + arr[i];
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;

        cout << pfx[t] << "\n";
    }
}