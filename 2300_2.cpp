#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> arr;
int mi = 2000000001;
int ansl, ansr;
int l, r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr.resize(n);
    for(auto &a : arr) cin >> a;

    l = 0;
    r = n - 1;

    while(l < r) {
        int sum = arr[l] + arr[r];

        if(abs(sum) < mi) {
            mi = abs(sum);
            ansl = l;
            ansr = r;
        } 

        sum < 0 ? l++ : r--;
    }

    cout << arr[ansl] << " ";
    cout << arr[ansr] << "\n";
}