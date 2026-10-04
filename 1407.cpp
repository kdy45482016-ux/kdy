#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> memo(50, 0);

bool can_merge(int l, int r) {
    if(l == 0) return false;
    int num = l * 10 + r;
    return num <= 34;
}

int func(int idx) {
    if(idx == 0) return arr[0] != 0;

    if(memo[idx] != 0) return memo[idx];

    memo[idx] = 0;

    if(arr[idx] != 0) {
        memo[idx] = func(idx - 1);
    }

    if(can_merge(arr[idx - 1], arr[idx])) {
        memo[idx] += (idx == 1 ? 1 : func(idx - 2));
    }

    return memo[idx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++) {
        arr.push_back(str[i] - '0');
    } 

    cout << func(arr.size() - 1) << "\n";
}   