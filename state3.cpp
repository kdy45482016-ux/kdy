#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map <string, vector <string>> m;
    int cnt = 0;
    
    for(int i = 0; i < n; i++){
        string city, state;
        cin >> city >> state;
        city = city.substr(0, 2);

        // 이전 값에서 찾기
        auto temp = m.find(city);
        if(temp != m.end() && temp != m.find(state)){
            for(auto a : m[city]){
                if(a == state) cnt += 1;
            }
        }

        m[state].push_back(city);
    }

    cout << cnt << endl;

    return 0;
}