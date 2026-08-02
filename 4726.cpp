#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<int> sum;

int bbh() { // b(1) -> b(i) -> h(n)
    int s = sum[n] - sum[1]; // 왼쪽 벌이 따는 꿀의 양
    int val = 0;

    for(int i = 2; i < n; i++) {
        val = max(val, sum[n] - sum[i] - arr[i]);
    }

    return s + val;
}

int hbb() { // h(1) -> b(i) -> b(n)
    int s = sum[n - 1]; // 오른쪽 벌이 따는 꿀의 양
    int val = 0;

    for(int i = 2; i < n; i++) {
        val = max(val, sum[i - 1] - arr[i]);
    }

    return s + val;
}

int bhb() { // b(1) -> h(i) -> b(n)
    int s = sum[n] - arr[1] - arr[n];
    int val = 0;

    for(int i = 2; i < n; i++) {
        val = max(val, arr[i]);
    }

    return s + val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    arr.resize(n + 1, 0);
    sum.resize(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }

    int ans = max(max(bbh(), hbb()), bhb());

    cout << ans << "\n";
}