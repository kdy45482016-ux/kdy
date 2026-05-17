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

const vector<Pos> move_pos = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

Pos s;
vector<string> arr;
vector<vector<int>> vis;
vector<Pos> check;
queue<Node> q;
int cnt, max_cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s.y >> s.x;

    arr.resize(s.y);
    vis.resize(s.y);

    for(int i = 0; i < s.y; i++) {
        vis[i].resize(s.x, -1);
        cin >> arr[i];
        for(int j = 0; j < s.x; j++) {
            if(arr[i][j] == 'L') check.push_back(Pos(i, j));
        }
    }

    for(int i = 0; i < check.size(); i++) {
        q.push(Node(check[i], 0));
        vis[check[i].y][check[i].x] = i;

        while(!q.empty()) {
            Pos pos = q.front().pos;
            cnt = q.front().cnt;

            q.pop();

            for(auto m : move_pos) {
                Pos new_pos = Pos(pos.y + m.y, pos.x + m.x);

                if(new_pos.y < 0 || new_pos.y >= s.y) continue;
                if(new_pos.x < 0 || new_pos.x >= s.x) continue;
                if(arr[new_pos.y][new_pos.x] == 'W') continue;
                if(vis[new_pos.y][new_pos.x] == i) continue;

                vis[new_pos.y][new_pos.x] = i;
                q.push(Node(new_pos, cnt + 1));
            }
        }

        max_cnt = max(cnt, max_cnt);
    }

    cout << max_cnt << "\n";
}