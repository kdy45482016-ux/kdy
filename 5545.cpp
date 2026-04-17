#include <iostream>

using namespace std;

typedef long long ll;

ll p, v, n;
ll a, b, c, d;

ll GCD(ll a, ll b){
    while(b != 0){
        auto t = a % b;
        a = b;
        b = t;
    }
    return a;
}

ll LCM(ll a, ll b){
    return a * b / GCD(a, b); 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p >> v >> n;

    b = n / LCM(p + 1, v + 1);
    c = n / (v + 1) - b;
    d = n / (p + 1) - b;
    a = n - (b + c + d);

    cout << a << " ";
    cout << b << " ";
    cout << c << " ";
    cout << d << "\n";
}