#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos{
    int y, x;

    Pos(){}

    Pos(int a, int b){
        y = a;
        x = b;
    }

    Pos operator+(const Pos& r) const{
        Pos temp = Pos(y + r.y, x + r.x);
        return temp;
    }

    bool operator==(const Pos& r) const{
        return (y == r.y) && (x == r.x);
    }
};

struct Node{
    Pos pos;
    int cnt;

    Node(Pos p, int c){
        pos = p;
        cnt = c;
    }
};

vector <Pos> moves = {
    Pos(1, 2),
    Pos(2, 1),
    Pos(2, -1),
    Pos(1, -2),
    Pos(-1, -2),
    Pos(-2, -1),
    Pos(-2, 1),
    Pos(-1, 2)
};

Pos board_size, root, target;
vector <vector <bool>> visited_arr;
queue <Node> q;

bool IsOverBoard(Pos pos, Pos board_size){
    if(pos.y >= board_size.y) return true;
    if(pos.x >= board_size.x) return true;
    if(pos.y < 0) return true;
    if(pos.x < 0) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> board_size.y >> board_size.x;
    visited_arr.resize(board_size.y);
    for(auto &e : visited_arr) e.resize(board_size.x, false);
    cin >> root.y >> root.x;
    cin >> target.y >> target.x;

    q.push(Node(root, 0));
    visited_arr[root.y][root.x] = true;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        if(cur.pos == target){
            cout << cur.cnt << "\n";
            return 0;
        }

        for(int i = 0; i < 8; i++){
            Pos new_pos = cur.pos + moves[i];

            if(IsOverBoard(new_pos, board_size)) continue;    // 범위 넘어감
            if(visited_arr[new_pos.y][new_pos.x]) continue; // 이미 방문함

            q.push(Node(new_pos, cur.cnt + 1));
            visited_arr[new_pos.y][new_pos.x] = true;
        }
    }
}