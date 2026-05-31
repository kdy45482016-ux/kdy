#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int y, x;
    Pos() {}
    Pos(int a, int b) { y = a; x = b; }
    const Pos operator+(const Pos& a) const { return { y + a.y, x + a.x }; }
};

struct Node {
    Pos pos;
    int dir;
    Node() {}
    Node(Pos a, int b) { pos = a; dir = b; }
};

const vector<Pos> move_val = { {0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
const vector<int> left_val = { 0, 4, 3, 1, 2 };
const vector<int> right_val = { 0, 3, 4, 2, 1 };

Pos s;
vector<vector<int>> arr;
vector<vector<vector<int>>> vis;
Node src, dst;
queue<pair<Node, int>> q;

bool is_over(Pos pos) {
    if (pos.y < 0 || pos.y >= s.y) return true;
    if (pos.x < 0 || pos.x >= s.x) return true;
    return false;
}

int turn_dir(int dir, bool is_left) {
    return is_left ? left_val[dir] : right_val[dir];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s.y >> s.x;

    arr.resize(s.y);
    vis.resize(s.y);

    for (int i = 0; i < s.y; i++) {
        arr[i].resize(s.x);
        vis[i].resize(s.x);

        for (int j = 0; j < s.x; j++) {
            cin >> arr[i][j];
            vis[i][j].resize(5, false);
        }
    }

    cin >> src.pos.y >> src.pos.x >> src.dir;
    cin >> dst.pos.y >> dst.pos.x >> dst.dir;

    src.pos = src.pos + Pos(-1, -1);
    dst.pos = dst.pos + Pos(-1, -1);

    q.push({ src, 0 });
    vis[src.pos.y][src.pos.x][src.dir] = true;

    while (!q.empty()) {
        Pos pos = q.front().first.pos;
        int dir = q.front().first.dir;
        int cnt = q.front().second;

        q.pop();

        if (pos.y == dst.pos.y && pos.x == dst.pos.x && dir == dst.dir) {
            cout << cnt << "\n";
            return 0;
        }

        for (int i = 0; i <= 1; i++) {
            int nxt_dir = turn_dir(dir, i);
            if (vis[pos.y][pos.x][nxt_dir]) continue;

            vis[pos.y][pos.x][nxt_dir] = true;
            q.push({ {pos, nxt_dir}, cnt + 1 });
        }

        Pos nxt_pos = pos + move_val[dir];

        while (
            !is_over(nxt_pos) &&
            arr[nxt_pos.y][nxt_pos.x] == 0 &&
            !vis[nxt_pos.y][nxt_pos.x][dir] &&
            !vis[nxt_pos.y][nxt_pos.x][0]
            ) {
            vis[nxt_pos.y][nxt_pos.x][dir] = true;
            vis[nxt_pos.y][nxt_pos.x][0] = true;

            q.push({ {nxt_pos, dir}, cnt + 1 });

            nxt_pos = nxt_pos + move_val[dir];
        }
    }
}