#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos {
    int y;
    int x;
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
vector<vector<int>> arr;
queue<Node> q;
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s.x >> s.y;

    arr.resize(s.y);
    
    for(int i = 0; i < s.y; i++) {
        arr[i].resize(s.x);
        for(int j = 0; j < s.x; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) q.push(Node(Pos(i, j), 0)); 
        }
    }

    while(!q.empty()) {
        Pos pos = q.front().pos;
        cnt = q.front().cnt;
        q.pop();

        for(auto m : move_pos) {
            Pos new_pos(pos.y + m.y, pos.x + m.x);

            if(new_pos.y < 0 || new_pos.y >= s.y) continue;
            if(new_pos.x < 0 || new_pos.x >= s.x) continue;
            if(arr[new_pos.y][new_pos.x] != 0) continue;

            arr[new_pos.y][new_pos.x] = 1;
            q.push(Node(new_pos, cnt + 1));
        }
    }

    bool is_remain = false;
    for(int i = 0; i < s.y && !is_remain; i++) {
        for(int j = 0; j < s.x && !is_remain; j++) {
            if(arr[i][j] == 0) is_remain = true;
        }
    }

    cout << (is_remain ? -1 : cnt) << "\n";
}