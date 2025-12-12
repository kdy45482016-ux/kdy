#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map <string, vector <string>> m;
    vector <vector <string>> v(n);

    for(int i = 0; i < n; i++){
        string city, state;
        cin >> city >> state;
        string temp = city.substr(0, 2);
        m[state].push_back(temp);
        v[i].push_back(city);
        v[i].push_back(state);
    }

    int cnt = 0;

    for(auto a : v){
        string temp = a[0].substr(0, 2);    // 도시의 앞 두 글자
        if(m.find(temp) != m.end() && m.find(temp) != m.find(a[1])){    // 도시에 해당하는 주가 있고 도시의 주와 같지 않으면
            for(auto b : m[temp]){  // 찾는 주의 도시들
                if(a[1] == b.substr(0, 2)){
                    // cout << a[0] << " " << a[1] << " : " << b << " " << temp << endl;
                    cnt += 1;
                }
            }
        }
    }

    cout << cnt / 2 << endl;

    return 0;
}