#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;

    cin >> n >> k;
    
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int sum = 0;
    vector<int> sum_arr;

    for(int i = 0; i < k; i++) sum += arr[i];
    sum_arr.push_back(sum);

    for(int i = k; i < n; i++) {
        sum -= arr[i - k];
        sum += arr[i];
        sum_arr.push_back(sum);
    }

    int max_val = -2000000000;
    for(auto a : sum_arr) max_val = max(max_val, a);

    cout << max_val << "\n";
}