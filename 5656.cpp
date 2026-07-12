#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<int> sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    arr.resize(n + 1, 0);
    sum.resize(n + 1, 0);

    string str;
    cin >> str;

    for(int i = 0; i < n; i++) {
        int num = str[i] - '0';
        arr[i + 1] = num;
        sum[i + 1] = sum[i] + num;
    }

    // 
}