#include <iostream>
#include <vector>

using namespace std;

int n, d, k, c;
vector<int> arr;
vector<int> chk;
int ma = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d >> k >> c;
    arr.resize(n);
    for(auto &a : arr) cin >> a;
    chk.resize(d + 1, 0);

    for(int i = 0; i < n; i++) {
        int cnt = 1;
        for(int j = i; j < i + k; j++) {
            int index = (j < n ? j : j - n + 1);
            if(chk[arr[index]] == i + 1 || arr[index] == c) continue;
            chk[arr[index]] = i + 1;
            cnt++;
        }

        ma = max(cnt, ma);
    }

    cout << ma << "\n";
}