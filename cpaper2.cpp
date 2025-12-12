#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector <vector <int>> paper;
int n, white = 0, blue = 0;


void Print2(int x, int y, int range)
{
    int arr[n][n];
    memset(arr, 0, sizeof(arr));

    for(int i = y; i < y + range; i++){
        for(int j = x; j < x + range; j++){
            arr[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void func2(int x, int y, int range)
{
    // cin.get();
    // cout << x << " " << y << " ~ " << range << endl;
    // Print2(x, y, range);

    int val = paper[y][x];
    bool check = true;
    
    // 크기 == 1
    if(range <= 1){
        val ? white++ : blue++;
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

    // 전부 같은 색
    if(check){
        val ? white++ : blue++;
        return;
    }

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

    cout << blue << endl << white << endl;
}