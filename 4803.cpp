#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct node {
    ll a;
    ll x;

    bool operator<(const node & r) const {
        if(x != r.x) return x < r.x;
        return a < r.a;
    }
};

int n, Q;
vector<node> arr;
vector<node> sum;

int bs(ll num) { // arr에서 num 이전 값의 위치 반환
    int l = 0;
    int r = n - 1;
    while(l <= r) {
        int m = (l + r) / 2;
        if(arr[m].x < num) l = m + 1;
        else if(arr[m].x > num) r = m - 1;
        else return m;
    }
    return r;
}

ll func(ll q) { // q에 대한 누적 거리 반환
    int k = bs(q);

    ll l, r;

    if(k == -1) l = 0L;
    else l = (q * sum[k].a) - sum[k].x;
    if(k == n - 1) r = 0L;
    else {
        ll sum_r_a = sum[n - 1].a;
        ll sum_r_x = sum[n - 1].x;
        
        if(k != -1) {
            sum_r_a -= sum[k].a;
            sum_r_x -= sum[k].x;
        }
        
        r = (sum_r_x) - (q * sum_r_a);
    }

    return l + r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> Q;

    arr.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].x;
    }

    sort(arr.begin(), arr.end());

    sum.resize(n);

    node temp = {0};
    for(int i = 0; i < n; i++) {
        temp.a += arr[i].a;
        temp.x += arr[i].a * arr[i].x;
        sum[i] = temp;
    }

    vector<int> query(Q);
    for(auto & a : query) cin >> a;
    for(auto a : query) cout << func((ll)a) << "\n";
}

/*
k : q 이전 값의 위치
q 기준 왼쪽 :
    i : 0 ~ k
    sigma(a[i] * (q - x[i]))
        -> q * sigma(a[i])
        -> - sigma(a[i] * x[i]) 
q 기준 오른쪽 :
    i : (k + 1) ~ (n - 1)
    sigma(a[i] * (x[i] - q))
        -> sigma(a[i] * x[i])
        -> - q * sigma(a[i])
*/