#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, s;
vector <int> c;
vector <int> y;
ll cost = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    c.resize(n);
    y.resize(n);
    for(int i = 0; i < n; i++){
        cin >> c[i] >> y[i];
    }

    for(int i = 0; i < n; i++){
        if((i != 0) && (c[i] > (c[i-1] + s))) c[i] = (c[i-1] + s);
        cost += (ll)(c[i] * y[i]);
    }

    cout << cost << "\n";
}