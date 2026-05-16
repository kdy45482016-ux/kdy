#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> move_y = { 2, 1, -1, -2, -2, -1, 1, 2 };
vector<int> move_x = { 1, 2, 2, 1, -1, -2, -2, -1 };

int size_y, size_x;
int start_y, start_x;
int end_y, end_x;
vector<vector<int>> vis;
queue<pair<pair<int, int>, int>> check; // first.first : y, first.second : x, second : count
int min_move;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> size_y >> size_x;
    cin >> start_y >> start_x;
    cin >> end_y >> end_x;

    vis.resize(size_y + 1);
    for (int i = 1; i <= size_y; i++) vis[i].resize(size_x + 1, false);

    check.push(make_pair(make_pair(start_y, start_x), 0));
    vis[start_y][start_x] = true;

    while (!check.empty()) {
        pair<int, int> cur_pos = check.front().first;
        int cur_cnt = check.front().second;
        check.pop();

        int cur_y = cur_pos.first;
        int cur_x = cur_pos.second;

        if (cur_y == end_y && cur_x == end_x) {
            min_move = cur_cnt;
            break;
        }

        for (int i = 0; i < move_y.size(); i++) {
            int new_y = cur_y + move_y[i];
            int new_x = cur_x + move_x[i];

            if (new_y < 1 || new_y > size_y) continue;
            if (new_x < 1 || new_x > size_x) continue;
            if (vis[new_y][new_x]) continue;

            check.push(make_pair(make_pair(new_y, new_x), cur_cnt + 1));
            vis[new_y][new_x] = true;
        }
    }

    cout << min_move << "\n";
}