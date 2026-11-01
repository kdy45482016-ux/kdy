#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, w;
vector<int> coin;
vector<int> memo;
int mv;

int func(int idx) {  // coin[0~idx] 최소 사용 개수
    if(memo[idx] != mv) return memo[idx];

    if(idx < 0) return mv;
    
    int cnt = 1;  // coin[idx] 1개 이상 사용
    int r = w - coin[idx];

    if(r < 0) return memo[idx] = min(func(idx-1), mv);  // coin[idx] 사용 불가능

    for(int i = idx; i >= 0; i--) {
        int d = r / coin[i];

        r -= coin[i] * d;
        cnt += d;
        
        if(r == 0) break;
    }

    if(r > 0) cnt = mv;

    return memo[idx] = min(func(idx-1), cnt); // 이전 최솟값 vs coin[idx] 쓰는 경우
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    coin.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    sort(coin.begin(), coin.end());

    cin >> w;

    mv = w + 1;
    memo.resize(n, mv);

    int rs = func(n-1);
    if(rs != mv) cout << rs << "\n";
    else cout << "impossible\n";
}