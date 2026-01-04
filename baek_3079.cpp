#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll n, m;
vector <ll> arr;
ll min1 = __LONG_LONG_MAX__, max1 = 0;

bool check(ll num)
{
    ll total = 0;  // 시간 내에 통과 가능한 인원

    for(auto a : arr){
        total += num / a;
        if(total >= m) return true; 
    }

    return false;
}

ll search()    // 총 심사시간의 최솟값
{
    ll start = min1;
    ll end = max1 * m;
    ll ans = end;
    
    while(start <= end){
        ll mid = (start + end) / 2;
        if(check(mid)){
            end = mid - 1;
            ans = min(ans, mid);
        } 
        else start = mid + 1;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.resize(n);
    for(auto &a : arr){
        cin >> a;
        if(a < min1) min1 = a;
        if(a > max1) max1 = a;
    }

    cout << search() << "\n";
}