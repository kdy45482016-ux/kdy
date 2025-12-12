#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> map;
int white = 0, blue = 0;

void func(int y, int x, int range)
{
    int value = map[y][x];
    bool isDif = false;
    
    if(range == 1){
        value ? blue++ : white++;
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
        value ? blue++ : white++;
        return;
    } 

    int r = range / 2;
    func(y, x, r);
    func(y, x + r, r);
    func(y + r, x, r);
    func(y + r, x + r, r);
}

int main()
{
    int n;
    cin >> n;

    map.resize(n);
    for(auto &a : map) a.resize(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    func(0, 0, n);

    cout << white << endl;
    cout << blue << endl;
}