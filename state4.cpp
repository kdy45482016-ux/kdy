#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map <pair <string, string>, int> m;

    for(int i = 0; i < n; i++){
        string city, state;
        cin >> city >> state;
        city = city.substr(0, 2);
        if(city == state) continue;
        m[{city, state}]++;
    }

    long long cnt = 0;

    for(auto p : m){
        auto key1 = p.first;
        auto key2 = make_pair(key1.second, key1.first);
        if(m.find(key2) != m.end() && key1 < key2){
            cnt += p.second * m[key2];
        }
    }

    cout << cnt << endl;

    return 0;
}