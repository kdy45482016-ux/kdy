#include <iostream>
#include <vector>

using namespace std;

int n;
vector <vector <int>> cost_arr;
vector <bool> visited_city;
int min_cost = 2147483647;

void DFS(int depth, int current_cost, int current_city){
    if(current_cost > min_cost) return;

    if(depth == n){
        if(cost_arr[current_city][0] != 0)
            min_cost = min(current_cost + cost_arr[current_city][0], min_cost);
        return;
    }

    for(int i = 1; i < n; i++){
        if(!visited_city[i] && cost_arr[current_city][i] != 0){
            visited_city[i] = true;
            DFS(depth + 1, current_cost + cost_arr[current_city][i], i);
            visited_city[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    cost_arr.resize(n);
    visited_city.resize(n, false);

    for(auto &a : cost_arr){
        a.resize(n);
        for(auto &b : a) cin >> b; 
    }

    DFS(1, 0, 0);

    cout << min_cost << "\n";
}