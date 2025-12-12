#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector <vector <int>> paper;
int n, white = 0, blue = 0;

void func2(int x, int y, int range)
{
    int val = paper[y][x];
    bool check = true;
    
    if(range <= 1){
        cout << val ? 1 : 0;
        return;
    }

    for(int i = y; i < y + range; i++){
        for(int j = x; j < x + range; j++){
            if(paper[i][j] != val){
                check = false;
                break;
            }
        }
        if(!check) break;
    }

    if(check){
        cout << val ? 1 : 0;
        return;
    }

    cout << 'X';

    func2(x, y, range / 2);
    func2(x + range / 2, y, range / 2);
    func2(x, y + range / 2, range / 2);
    func2(x + range / 2, y + range / 2, range / 2);
}

int main()
{
    cin >> n;

    paper.resize(n);
    for(int i = 0; i < n; i++) paper[i].resize(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> paper[i][j];
    }

    func2(0, 0, n);
}