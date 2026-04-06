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
        int dia1_pos = col + row;
        int dia2_pos = row - col + n - 1;
        
        if(!(used_col[col] || used_dia1[dia1_pos] || used_dia2[dia2_pos])){
            used_col[col] = true;
            used_dia1[dia1_pos] = true;
            used_dia2[dia2_pos] = true;

            DFS(row + 1);

            used_col[col] = false;
            used_dia1[dia1_pos] = false;
            used_dia2[dia2_pos] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    used_col.resize(n, false);
    used_dia1.resize(n * 2 - 1, false);
    used_dia2.resize(n * 2 - 1, false);
    
    DFS(0);

    cout << cnt << "\n";
}