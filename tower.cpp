#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> v(n);
    stack <pair <int, int>> s;
    vector <int> res(n);

    for(auto &a : res) a = 0;
    for(auto &a : v) cin >> a;
    reverse(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        if(!s.empty()){
            while(!s.empty() && s.top().second < v[i]){
                res[s.top().first] = n - i;
                s.pop();
            }
        }
        s.push(make_pair(i, v[i]));
    }

    reverse(res.begin(), res.end());

    for(auto a : res) cout << a << " ";
    cout << endl;

    return 0;
}