#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    int target;

    cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < q; i++){
        cin >> target;
        int idx = lower_bound(arr + 0, arr + n, target) - arr;
        
        if(idx >= n) cout << arr[n - 1] << "\n";
        else if(idx <= 0) cout << arr[0] << "\n";
        else if(target - arr[idx - 1] <= arr[idx] - target) cout << arr[idx - 1] << "\n";
        else cout << arr[idx] << "\n";
    }

    return 0;
}