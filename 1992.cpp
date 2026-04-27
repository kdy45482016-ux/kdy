#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> arr(7);
    for(auto &e : arr) cin >> e;
    sort(arr.begin(), arr.end());
    cout << arr[6] << "\n";
    cout << arr[5] << "\n";
}