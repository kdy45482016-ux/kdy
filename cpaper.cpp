#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector <vector <int>> paper;
int n, white = 0, blue = 0;

void Print(int x1, int y1, int x2, int y2){
    int arr[n][n];
    memset(arr, 0, sizeof(arr));

    for(int i = y1; i < y2; i++){
        for(int j = x1; j < x2; j++){
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

void func(int x1, int y1, int x2, int y2)
{
    // cin.get();
    // cout << x1 << " " << y1 << " ~ " << x2 << " " << y2 << endl;
    // Print(x1, y1, x2, y2);

    int val = paper[y1][x1];
    bool check = true;
    
    // 크기 == 1
    if(y2 - y1 <= 1 || x2 - x1 <= 1){
        val ? white++ : blue++;
        return;
    }

    for(int i = y1; i < y2; i++){
        for(int j = x1; j < x2; j++){
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

    // 문제 있음 (무한 반복)
    func(x1, y1, x2/2, y2/2);   // 0, 0 -> 4, 4
    func(x2/2, y1, x2, y2/2);   // 4, 0 -> 8, 4
    func(x1, y2/2, x2/2, y2);   // 0, 4 -> 4, 8
    func(x2/2, y2/2, x2, y2);   // 4, 4 -> 8, 8
}

int main()
{
    cin >> n;

    paper.resize(n);
    for(int i = 0; i < n; i++) paper[i].resize(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> paper[i][j];
    }

    func(0, 0, n, n);

    cout << blue << endl << white << endl;
}