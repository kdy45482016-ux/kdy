#include <iostream>
#include <vector>

using namespace std;

int n;
vector <bool> used_col;
vector <bool> used_dia1;
vector <bool> used_dia2;
int cnt = 0;

void DFS(int row){
    if(row == n){
        cnt++;
        return;
    }

    for(int col = 0; col < n; col++){
        if(!used_col[col] && !used_dia1[col + row] && !used_dia2[row - col + n - 1]){
            used_col[col] = true;
            used_dia1[col + row] = true;
            used_dia2[row - col + n - 1] = true;

            DFS(row + 1);

            used_col[col] = false;
            used_dia1[col + row] = false;
            used_dia2[row - col + n - 1] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    used_col.resize(n, false);
    used_dia1.resize(n * 2, false);
    used_dia2.resize(n * 2, false);
    
    DFS(0);

    cout << cnt << "\n";
}