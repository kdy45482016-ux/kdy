#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct POS{
    int y, x;

    POS(){}

    POS(int new_y, int new_x){
        y = new_y;
        x = new_x;
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
queue <POS> last_queue, cur_queue;
int min_move = 1000;

void func(int depth, POS cur_pos){
    if(depth >= min_move) return;

    if(cur_pos.y == pawn.y && cur_pos.x == pawn.x){
        min_move = depth;
        return;
    }

    for(auto m : moves){
        POS new_pos = POS(cur_pos.y + m.y, cur_pos.x + m.x);
        if(!visited_arr[new_pos.y][new_pos.x]){
            visited_arr[new_pos.y][new_pos.x] = true;
            cur_queue.push(new_pos);
        }
    }

    //
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> size.y >> size.x;
    visited_arr.resize(size.y);
    for(auto &e : visited_arr) e.resize(size.x, false);

    cin >> horse.y >> horse.x;
    cin >> pawn.y >> pawn.x;

    func(0, horse);

    cout << min_move << "\n";
}