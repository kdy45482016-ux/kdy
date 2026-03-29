#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector <string> arr;
vector <bool> used_col;
int cnt = 0;

void DFS(int row){
    if(row == n){
        cnt++;
        return;
    }

    for(int col = 0; col < n; col++){
        if(!used_col[col] && arr[row][col] == '.'){
            used_col[col] = true;
            DFS(row + 1);
            used_col[col] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    arr.resize(n);
    used_col.resize(n, false);

    for(int i = 0; i < n; i++) cin >> arr[i];

    DFS(0);

    cout << cnt << "\n";
}