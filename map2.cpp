#include <iostream>
#include <map>

using namespace std;

int main()
{
    map <int, int> m;

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        char c;
        cin >> c;
        int n;

        if(c == 'f'){
            cin >> n;
            if(m.find(n) != m.end()) cout << "YES " << m[n] << endl;
            else cout << "NO" << endl;
        }
        else if(c == 'a'){
            cin >> n;
            m[n] += 1;
        }
        else{
            cout << m.size() << endl;
        }
    }
}