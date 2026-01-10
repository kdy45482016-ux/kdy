#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll n, t;
vector <ll> arr;

bool check(ll num)
{
    ll sum = 0;
    for(auto a : arr) sum += min(a, num);
    return sum >= t;
}

ll search()
{
    ll left = 1;
    ll right = t;
    
    while(left <= right){
        ll mid = (left + right) / 2;
        if(check(mid)) right = mid - 1;
        else left = mid + 1;    
    }

    return left;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t;
    arr.resize(n);
    for(auto &a : arr){
        cin >> a;
    }

    cout << search() << "\n";
}