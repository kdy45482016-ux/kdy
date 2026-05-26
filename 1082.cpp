#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int y, x;
    Pos() {}
    Pos(int a, int b) {y = a; x = b;}
    Pos operator+(const Pos& a) {return {y + a.y, x + a.x};}
};

const vector<Pos> move_val = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool is_over(Pos cur_pos, Pos arr_size) {
    if(
        cur_pos.y < 0 ||
        cur_pos.x < 0 ||
        cur_pos.y >= arr_size.y ||
        cur_pos.x >= arr_size.x
    ) return true;
    return false;
} 

bool is_exist(char val, string str) {
    for(auto c : str) if(val == c) return true;
    return false;
}

Pos s;
vector<string> arr;
queue<Pos> fire;
queue<pair<Pos, int>> player;
vector<vector<int>> vis;
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s.y >> s.x;

    arr.resize(s.y);
    vis.resize(s.y);

    for(int i = 0; i < s.y; i++) {
        cin >> arr[i];

        vis[i].resize(s.x, false);

        for(int j = 0; j < s.x; j++) {
            if(arr[i][j] == '*') fire.push({i, j});
            else if(arr[i][j] == 'S') {
                player.push({{i, j}, 0});
                vis[i][j] = true;
            }
        }
    }

    while(!player.empty()) {
        vector<Pos> fire_arr;

        while(!fire.empty()) {
            fire_arr.push_back(fire.front());
            fire.pop();
        }

        for(auto pos_f : fire_arr) {
            for(auto m : move_val) {
                Pos npf = pos_f + m;

                if(is_over(npf, s)) continue;
                if(is_exist(arr[npf.y][npf.x],"*XD")) continue;

                arr[npf.y][npf.x] = '*';
                fire.push(npf);
            }
        }

        vector <pair<Pos, int>> player_arr;

        while(!player.empty()) {
            player_arr.push_back(player.front());
            player.pop();
        }

        for(auto node_p : player_arr) {
            Pos pos_p = node_p.first;
            cnt = node_p.second;

            for(auto m : move_val) {
                Pos npp = pos_p + m;

                if(is_over(npp, s)) continue;
                if(vis[npp.y][npp.x]) continue;
                if(is_exist(arr[npp.y][npp.x], "*X")) continue;

                if(arr[npp.y][npp.x] == 'D') {
                    cout << cnt + 1 << "\n";
                    return 0;
                }

                vis[npp.y][npp.x] = true;
                player.push({npp, cnt + 1});
            }
        }
    }

    cout << "impossible" << "\n";
}