#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <int> open(2);
vector <int> use;

int min_move = 1000;

int abs(int num){
    if(num < 0) return -num;
    return num;
}

void dfs(int index, int total_move){
    if(total_move >= min_move) return;

    if(index == m){
        min_move = total_move;
        return;
    }

    for(int i = 0; i < 2; i++){
        int init = open[i];
        int current_move = abs(use[index] - open[i]);
        open[i] = use[index];
        dfs(index + 1, total_move + current_move);
        open[i] = init;
    }    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(auto &e : open) cin >> e;
    cin >> m;

    use.resize(m);
    for(auto &e : use) cin >> e;

    dfs(0, 0);

    cout << min_move << "\n";
}