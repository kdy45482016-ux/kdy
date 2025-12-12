#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, tg;
    cin >> n >> q;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr + 0, arr + n);

    int cnt = 0;
    for(int i = 0; i < q; i++){
        cin >> tg;
        int idx = lower_bound(arr + 0, arr + n, tg) - arr;

        if(idx >= n || arr[idx] != tg){
            cout << tg << " ";
            cnt++;
        }
    }

    if(cnt == 0) cout << -1;
    cout << "\n";

    return 0;
}