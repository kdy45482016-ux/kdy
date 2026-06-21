// 수정 필요
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &a : arr) cin >> a;

    int l = 0, r = n - 1;
    int cnt = 0;
    int min_val = 2147483647;
    int al, ar;

    while(l < r) {
        int val = abs(arr[l] + arr[r]);
        if(val <= min_val) {
            min_val = val;
            al = arr[l];
            ar = arr[r];
        }
        int ver = ++cnt % 3;
        if(ver == 1) l++;
        else if(ver == 2) {l--; r--;}
        else l++; 
    }

    cout << al << " " << ar << "\n";
}