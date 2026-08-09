#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> arr;
vector<int> dist;
vector<int> sum;
vector<int> sum1;
vector<int> sum2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> k;

    arr.resize(n, 0);
    dist.resize(n, 0);
    sum.resize(n, 0);
    sum1.resize(n, 0);
    sum2.resize(n, 0);
    
    for(int i = 0 ; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = 1; i < n; i++) {
        dist[i] = arr[i] - arr[i - 1];
        sum[i] = sum[i - 1] + dist[i];
        sum1[i] = sum1[i - 1] + sum[i];
        sum2[i] = sum2[i - 1] + sum1[i];
    }

    int sum_val = 0;

    for(int i = 0; i < k - 1; i++) {
        sum_val += sum1[i];
    }

    int ans = 2100000000;

    for(int i = 0; i <= n - k; i++) {
        sum_val += sum1[i + k - 1];
        cout << sum_val << " ";
        ans = min(ans, sum_val);
        sum_val -= sum1[i];
    }
    cout << "\n";

    cout << ans << "\n";
    for(auto a : arr) cout << a << " "; cout << "\n";
    for(auto a : dist) cout << a << " "; cout << "\n";
    for(auto a : sum) cout << a << " "; cout << "\n";
    for(auto a : sum1) cout << a << " "; cout << "\n";
    for(auto a : sum2) cout << a << " "; cout << "\n";
}