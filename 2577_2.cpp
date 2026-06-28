#include <iostream>
#include <vector>

using namespace std;

int n, d, k, c;
vector<int> arr;
vector<int> chk;
int cnt = 1;
int max_cnt = 0;

int normalize_index(int index) {
    if (index < 0) return n - 1 + index;
    if (index >= n) return index - n;
    return index;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d >> k >> c;

    arr.resize(n);
    chk.resize(d, 0);

    for (auto& a : arr) cin >> a;

    for (int i = -1; i < k - 1; i++) {
        int index = normalize_index(i);
        int node = arr[index];

        chk[node]++;
        if (node != c && chk[node] == 1) cnt++;
    }

    int l = -1, r = k - 1;
    for (int i = 0; i < n; i++) {
        int nl = normalize_index(l);
        int nr = normalize_index(r);

        int lnode = arr[nl];
        int rnode = arr[nr];

        chk[lnode]--;
        if (lnode != c && chk[lnode] == 0) cnt--;

        chk[rnode]++;
        if (rnode != c && chk[rnode] == 1) cnt++;

        max_cnt = max(cnt, max_cnt);

        l++;
        r++;
    }

    cout << max_cnt << "\n";
}