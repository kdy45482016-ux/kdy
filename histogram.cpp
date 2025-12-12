#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define ll long long

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> v(n);
    vector <int> max(n);
    stack <pair <int, int>> s;

    for(auto &a : v) cin >> a;

    for(int i = 0; i < n; i++){
        while(!s.empty() && s.top().second > v[i]){
            max[s.top().first] = (i - s.top().first);
            s.pop();
        }
        s.push(make_pair(i, v[i]));
    }

    while(!s.empty()){
        max[s.top().first] = (n - s.top().first);
        s.pop();
    } 

    int m = n;
    for(int i = 0; i < n; i++){
        if(m < v[i] * max[i]) m = v[i] * max[i];
    }

    cout << m << endl;
    
    return 0;
}

// 0이 나오는 경우 고려