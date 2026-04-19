#include <iostream>
#include <vector>

using namespace std;

int n = 9;

vector <vector <int>> arr;

vector <int> pos_y;
vector <int> pos_x;

vector <vector <bool>> vis_y;
vector <vector <bool>> vis_x;
vector <vector <bool>> vis_s;

int s_index(int y, int x){
    return ((y / 3) * 3) + (x / 3);
}

bool can_fill(int y, int x, int num){
    if(vis_y[y][num]) return false;
    if(vis_x[x][num]) return false;
    if(vis_s[s_index(y, x)][num]) return false;

    return true;
}

bool dfs(int depth){
    if(depth == pos_y.size()) return true;

    int y = pos_y[depth];
    int x = pos_x[depth];

    for(int num = 1; num <= n; num++){
        if(!can_fill(y, x, num)) continue;

        arr[y][x] = num;
        vis_y[y][num] = vis_x[x][num] = vis_s[s_index(y, x)][num] = true;
        
        if(dfs(depth + 1)) return true;

        arr[y][x] = 0;
        vis_y[y][num] = vis_x[x][num] = vis_s[s_index(y, x)][num] = false;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // cin >> n;

    arr.resize(n);

    vis_y.resize(n);
    vis_x.resize(n);
    vis_s.resize(n);

    for(int i = 0; i < n; i++){
        arr[i].resize(n);
        vis_y[i].resize(n + 1, false);
        vis_x[i].resize(n + 1, false);
        vis_s[i].resize(n + 1, false);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            arr[i][j] = num;
            
            if(num == 0){
                pos_y.push_back(i);
                pos_x.push_back(j);
            }
            else{   // num != 0
                vis_y[i][num] = true;
                vis_x[j][num] = true;
                vis_s[s_index(i, j)][num] = true;
            }
        }
    }

    dfs(0);

    for(auto &i : arr){
        for(auto &j : i) cout << j << " ";
        cout << "\n";
    }
}