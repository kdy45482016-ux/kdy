#include <iostream>
#include <vector>

using namespace std;

vector<int> move_y = {0, -1, 0, 1};
vector<int> move_x = {1, 0, -1, 0};

int size_y, size_x;
vector<vector<int>> arr;
vector<vector<int>> vis;
int timer = 0, che_cnt = 0, mel_cnt = 0;
vector <int> ans;

int func(int y, int x){
    vis[y][x] = timer;

    int cnt = 0;

    for(int i = 0; i < 4; i++){
        int new_y = y + move_y[i];
        int new_x = x + move_x[i];

        if(new_y < 0 || new_y >= size_y) continue;
        if(new_x < 0 || new_x >= size_x) continue;

        if(vis[new_y][new_x] == timer) continue;
        if(arr[new_y][new_x] == 1){
            arr[new_y][new_x] = 2;
            vis[new_y][new_x] = timer;
            cnt++;
            continue;
        } 

        if(arr[new_y][new_x] == 2) arr[new_y][new_x] = 0;

        cnt += func(new_y, new_x);
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> size_y >> size_x;

    arr.resize(size_y);
    vis.resize(size_y);

    for(int i = 0; i < size_y; i++){
        arr[i].resize(size_x);
        vis[i].resize(size_x, 0);

        for(int j = 0; j < size_x; j++){
            cin >> arr[i][j];
            if(arr[i][j]) che_cnt++;
        }
    }

    while(che_cnt > mel_cnt){
        timer++;
        int mel = func(0, 0);
        mel_cnt += mel;
        ans.push_back(mel);
    }

    cout << timer << "\n";
    cout << ans.back() << "\n";
}