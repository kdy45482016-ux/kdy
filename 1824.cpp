#include <iostream>
#include <vector>

using namespace std;

int n = 9;
int cnt = 0;
vector <vector <int>> arr;
vector <int> pos_y(0);
vector <int> pos_x(0);
bool is_print = false;

bool can_fill(int y, int x, int num){
    for(int i = 0; i < n; i++) if(arr[i][x] == num) return false;
    for(int i = 0; i < n; i++) if(arr[y][i] == num) return false;

    int py = (y / 3) * 3;
    int px = (x / 3) * 3;
    
    for(int i = py; i < py + 3; i++){
        for(int j = px; j < px + 3; j++){
            if(arr[i][j] == num) return false;
        }
    }

    return true;
}

void dfs(int depth){
    if(is_print) return;

    if(depth == cnt){
        for(auto &i : arr){
            for(auto &j : i) cout << j << " ";
            cout << "\n";
        }
        is_print = true;
        return;
    }

    for(int i = 1; i <= 9; i++){
        int y = pos_y[depth];
        int x = pos_x[depth];

        if(!can_fill(y, x, i)) continue;

        arr[y][x] = i;
        dfs(depth + 1);
        arr[y][x] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    arr.resize(n);
    for(int i = 0; i < n; i++){
        arr[i].resize(n);
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(!arr[i][j]){
                cnt++;
                pos_y.push_back(i);
                pos_x.push_back(j);
            }
        }
    }

    dfs(0);
}