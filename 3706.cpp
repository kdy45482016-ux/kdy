#include <iostream>
#include <vector>

#define MAX 100000

using namespace std;

int n;
vector<int> arr;
vector<int> sum;
vector<int> cnt;
long long ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr.resize(n + 1, 0);
    sum.resize(n + 1, 0);
    cnt.resize(MAX * 2 * 100, 0);

    cnt[MAX * 100]++;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
        ans += cnt[MAX * 100 + sum[i]]++;
    }

    cout << ans << "\n";
}