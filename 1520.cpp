#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> memo;

int func(int n) {  // n번째를 밟았을 때의 최대값 반환
    if(n < 0) return 0;
    if(n == 0) return arr[n];

    if(memo[n] != -1) return memo[n];

    int a = func(n-2);
    int b = func(n-3) + arr[n-1];

    return memo[n] = max(a, b) + arr[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    arr.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    memo.resize(n, -1);

    cout << func(n - 1) << "\n";
}