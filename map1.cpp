#include <iostream>
#include <map>
using namespace std;

int main()
{
    map <string, int> m;

    for(int i = 0; ; i++){
        string input;
        cin >> input;
        if(input == "end") break;
        m[input] = i + 1;
    }

    cout << m.size() << endl;
    for(auto a : m){
        cout << a.first << " " << a.second << endl;
    }

    return 0;
}