#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
    priority_queue<ll, vector<ll>, greater<ll>> q;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        q.push(a);
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        ll money;
        cin >> money;

        ll a = q.top();
        a += money;
        q.pop();
        q.push(a);
    }

    for(int i = 0; i < n; i++){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}