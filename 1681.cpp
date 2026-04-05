#include <iostream>
#include <vector>

using namespace std;

int n;
vector <vector <int>> cost;
vector <bool> visited;
int min_cost = 2147483647;

void DFS(int dep, int sum, int last){
    if(sum > min_cost) return;

    if(dep == n){
        if(cost[last][0] != 0)
            min_cost = min(sum + cost[last][0], min_cost);
        return;
    }

    for(int i = 1; i < n; i++){
        if(!visited[i] && cost[last][i] != 0){
            visited[i] = true;
            DFS(dep + 1, sum + cost[last][i], i);
            visited[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cost.resize(n);
    visited.resize(n, false);

    for(auto &a : cost){
        a.resize(n);
        for(auto &b : a) cin >> b; 
    }

    DFS(1, 0, 0);

    cout << min_cost << "\n";
}