#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll Len(ll a, ll b){
    return a > b ? a - b : b - a;
}

ll Len2(ll a, ll b, ll c){
    ll len1 = Len(a, b), len2 = Len(b, c);
    return len1 < len2 ? len1 : len2;
}

int main()
{
    int n;
    cin >> n;
    
    map <ll, vector<ll>> m;

    for(int i = 0; i < n; i++){
        ll pos, color;
        cin >> pos >> color;
        m[color].push_back(pos);
    }

    ll sum = 0;

    for(auto &a : m){
        if(a.second.size() <= 1) continue;
        sort(a.second.begin(), a.second.end());
        for(int i = 0; i < a.second.size(); i++){
            if(i == 0) sum += Len(a.second[0], a.second[1]);
            else if(i == a.second.size() - 1) sum += Len(a.second[i-1], a.second[i]);
            else sum += Len2(a.second[i-1], a.second[i], a.second[i+1]);
        }
    }

    cout << sum << endl;

    return 0;
}