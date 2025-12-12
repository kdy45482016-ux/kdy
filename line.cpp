#include <iostream>
#include <map>

typedef long long ll;

using namespace std;

ll func(ll n) // 1 ~ n 까지 더하기
{
    ll num = (n + 1) * (n / 2);
    if(n % 2 == 1) num += n / 2 + 1;
    return num;
}

int main()
{
    ll n;
    cin >> n;

    map <ll, ll> x, y;
    
    for(ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        x[a] += 1;
        y[b] += 1;
    }

    ll cnt = 0;

    for(auto a : x){
        if(a.second <= 1) continue;
        cnt += func(a.second - 1);
    }

    for(auto a : y){
        if(a.second <= 1) continue;
        cnt += func(a.second - 1);
    }

    cout << cnt << endl;

    return 0;
}