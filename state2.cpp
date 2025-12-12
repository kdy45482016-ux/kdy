#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map <string, vector <string>> m;

    for(int i = 0; i < n; i++){
        string city, state;
        cin >> city >> state;
        m[state].push_back(city.substr(0, 2));
    }

    int cnt = 0;

    for(auto a : m){    // 주(a.first)
        for(auto b : a.second){ // 도시(b)
            if(m.find(b) == m.end()) continue;
            if(m.find(a.first) == m.find(b)) continue;
            for(auto c : m[b]){ // 찾은 주의 도시들을 확인하기
                if(a.first == c) cnt += 1;  // 주 == 도시
            }
        }
    }

    cout << cnt / 2 << endl;

    return 0;
}