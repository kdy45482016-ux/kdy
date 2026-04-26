#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> min_food(4);
vector <vector <int>> food;

int min_cost = 7501;
vector <int> ans;
vector <int> visited;

void dfs(int index, vector <int> fnc){
    if(fnc[4] > min_cost) return;

    if(index == n){
        for(int i = 0; i < 4; i++) if(fnc[i] < min_food[i]) return;
        if(min_cost == fnc[4]) for(int i = 0; i < min(ans.size(), visited.size()); i++) if(ans[i] < visited[i]) return;
        min_cost = fnc[4];
        ans = visited;
        return;
    }

    visited.push_back(index + 1);
    auto temp = fnc;
    for(int i = 0; i < 5; i++) temp[i] += food[index][i]; 
    dfs(index + 1, temp);
    visited.pop_back();

    dfs(index + 1, fnc);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(auto &e : min_food) cin >> e;

    food.resize(n);
    for(auto &i : food){
        i.resize(5);
        for(auto &j : i) cin >> j;
    }

    dfs(0, vector <int> (5, 0));

    if(min_cost == 7501) min_cost = -1;

    cout << min_cost << "\n";
    for(auto e : ans) cout << e << " ";
    cout << "\n";
}