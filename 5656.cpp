#include <iostream>
#include <vector>

#define MAX 800000
#define MIN 100000

using namespace std;

int n;
vector<int> prefix;
vector<int> cnt;
long long ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    prefix.resize(n + 1, 0);
    cnt.resize(MAX + MIN, 0);

    string str;
    cin >> str;

    for(int i = 0; i < n; i++) {
        int num = str[i] - '0';
        num -= 1;
        prefix[i + 1] = prefix[i] + num;
    }

    for(int i = 0; i <= n; i++) {
        ans += (long long)cnt[MIN + prefix[i]]++;
    }

    cout << ans << "\n";
}