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
const int die_time = 3;

Pos size_val;
vector<string> arr;
Pos s_pos;
queue<Node> check;
int count;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> size_val.x >> size_val.y;

    arr.resize(size_val.y);
    for(int i = 0; i < size_val.y; i++) cin >> arr[i];

    cin >> s_pos.x >> s_pos.y;
    s_pos.x--;
    s_pos.y--;

    check.push(Node(s_pos, die_time));
    arr[s_pos.y][s_pos.x] = '2';

    while(!check.empty()) {
        Pos cur_pos = check.front().pos;
        count = check.front().cnt;
        check.pop();

        for(auto m : move_pos) {
            Pos new_pos = Pos(cur_pos.y + m.y, cur_pos.x + m.x);
            
            if(new_pos.y < 0 || new_pos.y >= size_val.y) continue;
            if(new_pos.x < 0 || new_pos.x >= size_val.x) continue;
            if(arr[new_pos.y][new_pos.x] != '1') continue;

            arr[new_pos.y][new_pos.x] = '2';
            check.push(Node(new_pos, count + 1));
        }
    }

    int live_cnt = 0;
    for(int i = 0; i < size_val.y; i++) {
        for(int j = 0; j < size_val.x; j++) {
            if(arr[i][j] == '1') live_cnt++;
        }
    }

    cout << count << "\n";
    cout << live_cnt << "\n";
}