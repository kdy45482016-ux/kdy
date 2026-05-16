#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> move_y = { 2, 1, -1, -2, -2, -1, 1, 2 };
vector<int> move_x = { 1, 2, 2, 1, -1, -2, -2, -1 };

int size_y, size_x;
int start_y, start_x;
int end_y, end_x;
vector<vector<int>> vis;
queue<int> yq, xq, cq;
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> size_y >> size_x;
    cin >> start_y >> start_x;
    cin >> end_y >> end_x;

    vis.resize(size_y + 1);
    for (int i = 1; i <= size_y; i++) vis[i].resize(size_x + 1, false);

    yq.push(start_y);
    xq.push(start_x);
    cq.push(0);

    vis[start_y][start_x] = true;

    while (!cq.empty()) {
        int cur_y = yq.front();
        int cur_x = xq.front();
        cnt = cq.front();

        yq.pop();
        xq.pop();
        cq.pop();

        if (cur_y == end_y && cur_x == end_x) break;

        for (int i = 0; i < move_y.size(); i++) {
            int new_y = cur_y + move_y[i];
            int new_x = cur_x + move_x[i];

            if (new_y < 1 || new_y > size_y) continue;
            if (new_x < 1 || new_x > size_x) continue;
            if (vis[new_y][new_x]) continue;

            yq.push(new_y);
            xq.push(new_x);
            cq.push(cnt + 1);

            vis[new_y][new_x] = true;
        }
    }

    cout << cnt << "\n";
}