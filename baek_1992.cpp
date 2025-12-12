#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> map;

void func(int y, int x, int range)
{
    int value = map[y][x];
    bool isDif = false;
    
    if(range == 1){
        cout << value;
        return;
    } 

    for(int i = y; i < y + range; i++){
        for(int j = x; j < x + range; j++){
            if(map[i][j] != value){
                isDif = true;
                break;
            }
        }
        if(isDif) break;
    }

    if(!isDif){
        cout << value;
        return;
    } 

    cout << "(";
    int r = range / 2;
    func(y, x, r);
    func(y, x + r, r);
    func(y + r, x, r);
    func(y + r, x + r, r);
    cout << ")";
}

int main()
{
    int n;
    cin >> n;

    map.resize(n);
    for(auto &a : map) a.resize(n);

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++){
            map[i][j] = str[j] - '0';
        }
    }

    func(0, 0, n);

    cout << endl;
}