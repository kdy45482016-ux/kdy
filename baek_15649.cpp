#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <int> ans;
vector <bool> visited;

void DFS(int depth){
    // 특정 깊이(m)에 도달하면 출력
    if(depth == m){
        for(auto e : ans) cout << e << " ";
        cout << "\n";
        return;
    }

    for(int i = 1; i < n + 1; i++){
        if(visited[i]) continue;

        visited[i] = true;
        ans.push_back(i);

        DFS(depth + 1);

        visited[i] = false;
        ans.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    visited.resize(n + 1, false);

    DFS(0);
}