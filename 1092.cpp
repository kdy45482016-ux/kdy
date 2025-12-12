#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

ll mod = 20091024;

// return : n ^ m
ll func(ll n, ll m)
{
    if(m == 1) return n % mod;
    if(m == 0) return 1;

    return (func(n, m / 2) * func(n, m / 2)) % mod;
}

int main()
{
    ll a, b;
    cin >> a >> b;

    ll ans = 1;

    for(ll i = 0; b > 0; i++){
        if(b % 2){
            ans *= func(a, pow(2, i));
            ans = ans % mod;
        }
        b /= 2;
    }

    cout << ans << endl;
}
