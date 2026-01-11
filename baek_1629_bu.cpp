#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll A, B, C;
    cin >> A >> B >> C;

    ll ans = 1;
    while(B > 0){
        if(B % 2) ans = (ans * A) % C;
        A = (A * A) % C;
        B /= 2;
    }

    cout << ans << "\n";
}