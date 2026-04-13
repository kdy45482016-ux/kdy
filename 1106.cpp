#include <iostream>
#include <vector>

using namespace std;

struct POS{
    int y, x;

    POS() {}

    POS(int a, int b){
        y = a;
        x = b;
    }

    bool operator<(const POS& r) const{
        if(y != r.y) return y < r.y;
        return x < r.x;
    }

    bool operator==(const POS& r) const{
        return y == r.y && x == r.x;
    }

    POS operator+(const POS& r) const{
        return POS(y + r.y, x + r.x);
    }
};

vector <POS> moves = {
    POS(1, 2),
    POS(2, 1),
    POS(2, -1),
    POS(1, -2),
    POS(-1, -2),
    POS(-2, -1),
    POS(-2, 1),
    POS(-1, 2)
};

POS size, horse, pawn;

vector <vector <bool>> visited_arr;
int min_move = 2147483647;

void DFS(int depth, POS pos){
    if(depth >= min_move) return;

    if(pos == pawn){
        min_move = depth;
        return;
    }

    for(int i = 0; i < 8; i++){
        POS new_pos = pos + moves[i];
        if(new_pos.y >= size.y || new_pos.x >= size.x) continue;  // 판 넘어감
        if(visited_arr[new_pos.y][new_pos.x]) continue;    //이미 방문함
        
        visited_arr[new_pos.y][new_pos.x] = true;
        DFS(depth + 1, new_pos);
        visited_arr[new_pos.y][new_pos.x] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> size.y >> size.x;
    visited_arr.resize(size.y);
    for(auto &e : visited_arr) e.resize(size.x);

    cin >> horse.y >> horse.x;
    cin >> pawn.y >> pawn.x;

    DFS(0, horse);

    cout << min_move << "\n";
}