#include <iostream>

using namespace std;

typedef long long ll;

ll func(ll a, ll b, ll c)
{
    if(b == 0) return 1;
    if(b == 1) return a % c;    

    ll temp = func(a, b/2, c) % c;
    ll ans = (temp * temp) % c;
    if(b % 2) ans = (ans * a) % c;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll A, B, C;
    cin >> A >> B >> C;

    cout << func(A, B, C) << "\n";
}