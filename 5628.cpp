#include <iostream>
#include <vector>

using namespace std;

void set_arr(vector<int> & arr, int num) {
    arr[1] += 1;
    arr[num + 1] -= 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cin >> n >> h;

    vector<int> arr1(h + 1, 0);
    vector<int> arr2(h + 1, 0);

    for(int i = 0; i < n; i++) {
        int s;
        cin >> s;

        if(i % 2 == 0) set_arr(arr1, s);
        else set_arr(arr2, s);
    }

    vector<int> pfx1(h + 1, 0);
    vector<int> pfx2(h + 1, 0);

    for(int i = 1; i <= h; i++) {
        pfx1[i] = pfx1[i - 1] + arr1[i];
        pfx2[i] = pfx2[i - 1] + arr2[i];
    }

    int mi = 2147483647;
    int cnt = 0;

    for(int i = 1; i <= h; i++) {
        int num = pfx1[i] + pfx2[h - i + 1];

        if(num < mi) {
            mi = num;
            cnt = 0;
        }

        if(mi == num) cnt++;
    }

    cout << mi << " " << cnt << "\n";
}