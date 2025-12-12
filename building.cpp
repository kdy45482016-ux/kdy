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

    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(!s.empty()){
            while(!s.empty() && s.top().second < v[i]){
                res[s.top().first] = i;
                s.pop();
            }
        }
        s.push(make_pair(i, v[i]));
    }

    for(auto a : res) cout << (a == 0 ? 0 : a + 1) << endl;

    return 0;
}