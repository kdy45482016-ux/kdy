#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector <int> kit;
vector <bool> visited;
int sum = 0;
int cnt = 0;

void DFS(int depth){
    if(depth == n){
        cnt++;
        return;
    }

    for(int i = 0; i < n; i++){
        if(visited[i] || sum + kit[i] < k) continue;
        
        visited[i] = true;
        sum += (kit[i] - k);

        DFS(depth + 1);

        visited[i] = false;
        sum -= (kit[i] - k);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    visited.resize(n, false);
    kit.resize(n);

    for(int i = 0; i < n; i++) cin >> kit[i];

    DFS(0);

    cout << cnt << "\n";
}