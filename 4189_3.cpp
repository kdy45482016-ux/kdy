#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int y, x;

    Pos() {}

    Pos(int a, int b) {
        y = a;
        x = b;
    }
};

struct Node {
    Pos pos;
    int cnt;

    Node() {}

    Node(Pos a, int b) {
        pos = a;
        cnt = b;
    }
};

vector<Pos> move_pos = {
    Pos(2, 1),
    Pos(1, 2),
    Pos(-1, 2),
    Pos(-2, 1),
    Pos(-2, -1),
    Pos(-1, -2),
    Pos(1, -2),
    Pos(2, -1)
};

Pos size_val, start_point, end_point;
vector<vector<int>> vis;
queue<Node> check;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> size_val.y >> size_val.x;
    cin >> start_point.y >> start_point.x;
    cin >> end_point.y >> end_point.x;

    vis.resize(size_val.y + 1);
    for (int i = 1; i <= size_val.y; i++) vis[i].resize(size_val.x + 1, false);

    check.push(Node(Pos(start_point), 0));

    vis[start_point.y][start_point.x] = true;

    while (!check.empty()) {
        Node node = check.front();
        check.pop();

        if(node.pos.y == end_point.y && node.pos.x == end_point.x){
            cout << node.cnt << "\n";
            return 0;
        }

        for (int i = 0; i < move_pos.size(); i++) {
            Node new_node = Node(Pos(node.pos.y + move_pos[i].y, node.pos.x + move_pos[i].x), node.cnt + 1);

            if (new_node.pos.y < 1 || new_node.pos.y > size_val.y) continue;
            if (new_node.pos.x < 1 || new_node.pos.x > size_val.x) continue;
            if (vis[new_node.pos.y][new_node.pos.x]) continue;

            vis[new_node.pos.y][new_node.pos.x] = true;

            check.push(new_node);
        }
    }
}