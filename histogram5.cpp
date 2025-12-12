#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

typedef long long ll;

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    stack <int> s;
    ll max = 0;

    for(int i = 0; i < n; i++){
        while(!s.empty() && arr[s.top()] >= arr[i]){
            ll area = arr[s.top()];
            s.pop();

            if(s.empty()) area *= i;
            else area *= i - s.top() - 1;

            if(area > max) max = area;
        }
        s.push(i);
    }

    while(!s.empty()){
        ll area = arr[s.top()];
        s.pop();

        if(s.empty()) area *= n;
        else area *= n - s.top() - 1;

        if(area > max) max = area;
    }

    cout << max << endl;

    return 0;
}